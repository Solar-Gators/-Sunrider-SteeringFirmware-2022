// File for User C++ Code

#include "user.hpp"
#include "etl/to_string.h"
#include "etl/format_spec.h"
#include "etl/string_utilities.h"
#include "UI.hpp"

using namespace SolarGators;

extern "C" void CPP_UserSetup(void);
extern "C" void CPP_HandleGPIOInterrupt(uint16_t GPIO_Pin);

void UpdateSignals();
void UpdateUI();
void SendCanMsgs();
void HandleEco();
void HandleHeadLights();
void HandleCruise();
void HandleReverse();

// OS Configs
osTimerId_t signal_timer_id;
osTimerAttr_t signal_timer_attr =
{
    .name = "lights_led"
};
/* Definitions for UI Updater */
osThreadId_t ui_thread_id;
uint32_t ui_stack[ 256 ];
StaticTask_t ui_control_block;
const osThreadAttr_t ui_thread_attributes = {
  .name = "UI",
  .cb_mem = &ui_control_block,
  .cb_size = sizeof(ui_control_block),
  .stack_mem = &ui_stack[0],
  .stack_size = sizeof(ui_stack),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for CAN Tx Thread */
osTimerId_t can_tx_timer_id;
osTimerAttr_t can_tx_timer_attr =
{
    .name = "CAN Tx"
};

uint32_t PULSE = 500;

void CPP_UserSetup(void)
{
  // Setup Actions
  // Note: These binds really abuse the stack and we should figure out a way to avoid them
  //       since we are heavily constrained.
  {
    using namespace SolarGators::DataModules;
    // Left Side
    left_turn.action_ = std::bind(&SteeringController::ToggleLeftTurnSignal, &LightsState);
    cruise_minus.action_ = std::bind(&SteeringController::DecreaseCruiseSpeed, &LightsState);
    eco.action_ = HandleEco;
    headlights.action_ = HandleHeadLights;
    hazards.action_ = std::bind(&SteeringController::ToggleHazards, &LightsState);
    // Right Side
    right_turn.action_ = std::bind(&SteeringController::ToggleRightTurnSignal, &LightsState);
    cruise_plus.action_ = std::bind(&SteeringController::IncreaseCruiseSpeed, &LightsState);
    horn.action_ = std::bind(&SteeringController::ToggleHorn, &LightsState);
    cruise.action_ = HandleCruise;
    reverse.action_ = HandleReverse;
  }
  // Add to Button Group
  // Left side
  LightsState.AddButton(&left_turn);
  LightsState.AddButton(&cruise_minus);
  LightsState.AddButton(&eco);
  LightsState.AddButton(&headlights);
  LightsState.AddButton(&hazards);
  // Right side
  LightsState.AddButton(&right_turn);
  LightsState.AddButton(&cruise_plus);
  LightsState.AddButton(&horn);
  LightsState.AddButton(&cruise);
  LightsState.AddButton(&reverse);
  // Load the CAN Controller
  CANController.AddRxModule(&BMS_Rx_0);
  CANController.AddRxModule(&Motor_Rx_0);
  // Start Thread that Handles Turn Signal LEDs
  signal_timer_id = osTimerNew((osThreadFunc_t)UpdateSignals, osTimerPeriodic, NULL, &signal_timer_attr);
  if (signal_timer_id == NULL)
  {
      Error_Handler();
  }
  osTimerStart(signal_timer_id, 500);
  // Start Thread that updates screen
  ui_thread_id = osThreadNew((osThreadFunc_t)UpdateUI, NULL, &ui_thread_attributes);
  if (signal_timer_id == NULL)
  {
      Error_Handler();
  }
  // Start Thread that sends CAN Data
  can_tx_timer_id = osTimerNew((osThreadFunc_t)SendCanMsgs, osTimerPeriodic, NULL, &can_tx_timer_attr);
  if (can_tx_timer_id == NULL)
  {
      Error_Handler();
  }
  CANController.Init();
  osTimerStart(can_tx_timer_id, 100);
}

void UpdateSignals()
{
  osMutexAcquire(LightsState.mutex_id_, osWaitForever);
  if(LightsState.GetHazardsStatus())
  {
    lt_indicator.Toggle();
    rt_indicator.Toggle();
  }
  else if(LightsState.GetRightTurnStatus())
    rt_indicator.Toggle();
  else if(LightsState.GetLeftTurnStatus())
    lt_indicator.Toggle();
  if(!LightsState.GetHazardsStatus() && !LightsState.GetRightTurnStatus())
    HAL_GPIO_WritePin(RT_Led_GPIO_Port, RT_Led_Pin, GPIO_PIN_RESET);
  if(!LightsState.GetHazardsStatus() && !LightsState.GetLeftTurnStatus())
      HAL_GPIO_WritePin(LT_Led_GPIO_Port, LT_Led_Pin, GPIO_PIN_RESET);
  osMutexRelease(LightsState.mutex_id_);
}

void UpdateUI()
{
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  // LCD
  SolarGators::Drivers::ILI9341 Display(ILI9341_TFTWIDTH, ILI9341_TFTHEIGHT);
  Display.Init();
  // This will initialize the UI
  SolarGators::Drivers::UI ui(Display);
  float test_val = 0.0;
  for (int i = 0; i < 1000; ++i)
  {
    ui.UpdateSpeed(test_val);
    test_val += 0.1;
    osDelay(50);
  }

  while(1)
  {
    osDelay(100);
  }
}

void SendCanMsgs()
{
  CANController.Send(&LightsState);
  McReq.SetRequestAllFrames();
  CANController.Send(&McReq);
}

void CPP_HandleGPIOInterrupt(uint16_t GPIO_Pin)
{
  LightsState.HandlePress(GPIO_Pin);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  CANController.SetRxFlag();
  HAL_CAN_DeactivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
}

void HandleEco()
{
  LightsState.ToggleEco();
  eco_indicator.Toggle();
}
void HandleHeadLights()
{
  LightsState.ToggleHeadlights();
  hl_indicator.Toggle();
}
void HandleCruise()
{
  LightsState.ToggleCruise();
  cr_indicator.Toggle();
}
void HandleReverse()
{
  LightsState.ToggleReverse();
  rev_indicator.Toggle();
}
