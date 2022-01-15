// File for User C++ Code

#include "user.hpp"

using namespace SolarGators;

extern "C" void CPP_UserSetup(void);
extern "C" void CPP_HandleGPIOInterrupt(uint16_t GPIO_Pin);
extern "C" void CPP_HandleCANRxInterrupt();

void UpdateTurnSignals();
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
uint32_t ui_stack[ 64 ];
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

void CPP_UserSetup(void)
{
  // Setup Actions
  // Note: These binds really abuse the stack and we should figure out a way to avoid them
  //       since we are heavily constrained.
  {
    using namespace SolarGators::DataModules;
    // Left Side
    left_turn.action_ = std::bind(&SteeringController::ToggleLeftTurnSignal, &Controller);
    cruise_minus.action_ = std::bind(&SteeringController::DecreaseCruiseSpeed, &Controller);
    eco.action_ = HandleEco;
    headlights.action_ = HandleHeadLights;
    hazards.action_ = std::bind(&SteeringController::ToggleHazards, &Controller);
    // Right Side
    right_turn.action_ = std::bind(&SteeringController::ToggleRightTurnSignal, &Controller);
    cruise_plus.action_ = std::bind(&SteeringController::IncreaseCruiseSpeed, &Controller);
    horn.action_ = std::bind(&SteeringController::ToggleHorn, &Controller);
    cruise.action_ = HandleCruise;
    reverse.action_ = HandleReverse;
  }
  // Add to Button Group
  // Left side
  Controller.AddButton(&left_turn);
  Controller.AddButton(&cruise_minus);
  Controller.AddButton(&eco);
  Controller.AddButton(&headlights);
  Controller.AddButton(&hazards);
  // Right side
  Controller.AddButton(&right_turn);
  Controller.AddButton(&cruise_plus);
  Controller.AddButton(&horn);
  Controller.AddButton(&cruise);
  Controller.AddButton(&reverse);
  // Load the CAN Controller
  CANController.AddRxModule(&Bms);
  CANController.AddRxModule(&McRx0);
  // Start Thread that Handles Turn Signal LEDs
  signal_timer_id = osTimerNew((osThreadFunc_t)UpdateTurnSignals, osTimerPeriodic, NULL, &signal_timer_attr);
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
  signal_timer_id = osTimerNew((osThreadFunc_t)UpdateTurnSignals, osTimerPeriodic, NULL, &signal_timer_attr);
  if (signal_timer_id == NULL)
  {
      Error_Handler();
  }
  osTimerStart(signal_timer_id, 50);
}

void UpdateTurnSignals()
{
  osMutexAcquire(Controller.mutex_id_, osWaitForever);
  if(Controller.GetHazardsStatus())
    lt_indicator.Toggle();
  else if(Controller.GetRightTurnStatus())
    rt_indicator.Toggle();
  else if(Controller.GetLeftTurnStatus())
    lt_indicator.Toggle();
  if(!Controller.GetHazardsStatus() && !Controller.GetRightTurnStatus())
    HAL_GPIO_WritePin(RT_Led_GPIO_Port, RT_Led_Pin, GPIO_PIN_RESET);
  if(!Controller.GetHazardsStatus() && !Controller.GetLeftTurnStatus())
      HAL_GPIO_WritePin(LT_Led_GPIO_Port, LT_Led_Pin, GPIO_PIN_RESET);
  osMutexRelease(Controller.mutex_id_);
}

void UpdateUI()
{
  HY28b lcd(&hspi1, false);
  Drivers::UI gui(HY28b::BLACK, lcd);
  uint8_t i = 0;
  while(1)
  {
    // TODO: Remove this was for testing
    gui.UpdateSpeed(i++);
    if(i > 99)
      i = 0;
    osMutexAcquire(McRx0.mutex_id_, osWaitForever);
    // Get Speed from Mitsuba
    uint16_t rpm = McRx0.GetMotorRPM();
    // Get Current from Mitsuba
    gui.UpdateCurrent(McRx0.GetBatteryCurrent());
    osMutexRelease(McRx0.mutex_id_);
    // Get SOC from BMS
    osMutexAcquire(Bms.mutex_id_, osWaitForever);
    gui.UpdateSOC(Bms.GetPackVoltage());
    osMutexRelease(Bms.mutex_id_);
    osDelay(100);
  }
}

void SendCanMsgs()
{
  CANController.Send(&Controller);
  McReq.SetRequestAllFrames();
  CANController.Send(&McReq);
}

void CPP_HandleGPIOInterrupt(uint16_t GPIO_Pin)
{
  Controller.HandlePress(GPIO_Pin);
}

void CPP_HandleCANRxInterrupt()
{
  CANController.HandleReceive();
}

void HandleEco()
{
  Controller.ToggleEco();
  eco_indicator.Toggle();
}
void HandleHeadLights()
{
  Controller.ToggleHeadlights();
  hl_indicator.Toggle();
}
void HandleCruise()
{
  Controller.ToggleCruise();
  cr_indicator.Toggle();
}
void HandleReverse()
{
  Controller.ToggleReverse();
  rev_indicator.Toggle();
}
