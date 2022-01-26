

#ifndef USER_HPP_
#define USER_HPP_

#include <HY28b.hpp>
#include <UI.hpp>
#include "main.h"
#include "SteeringController.hpp"
#include "Mitsuba.hpp"
#include "OrionBMS.hpp"
#include "DataModuleInfo.hpp"
#include "Button.hpp"
#include "CAN.hpp"


SolarGators::DataModules::SteeringController LightsState;
SolarGators::DataModules::MitsubaRequest McReq(SolarGators::DataModuleInfo::MOTORTX_RL_MSG_ID);
SolarGators::DataModules::OrionBMS Bms(SolarGators::DataModuleInfo::Orion_Id);
SolarGators::DataModules::MitsubaRx0 McRx0(SolarGators::DataModuleInfo::MOTORRX0_RL_MSG_ID);
// Forward Declares
extern SPI_HandleTypeDef hspi1;
extern CAN_HandleTypeDef hcan;
SolarGators::Drivers::CANDriver CANController(&hcan, 0);

// Buttons
// Left Side
SolarGators::Drivers::Button left_turn    ("Left Turn", LT_Button_GPIO_Port, LT_Button_Pin);
SolarGators::Drivers::Button cruise_minus ("Cruise Minus", Cruise_M_GPIO_Port, Cruise_M_Pin);
SolarGators::Drivers::Button eco          ("Eco Mode", Eco_Button_GPIO_Port, Eco_Button_Pin);
SolarGators::Drivers::Button headlights   ("Headlights", HL_Button_GPIO_Port, HL_Button_Pin);
SolarGators::Drivers::Button hazards      ("Left Turn", Haz_Button_GPIO_Port, Haz_Button_Pin);
// Right Side
SolarGators::Drivers::Button right_turn   ("Right Turn", RT_Button_GPIO_Port, RT_Button_Pin);
SolarGators::Drivers::Button cruise_plus  ("Cruise Plus", Cruise_P_GPIO_Port, Cruise_P_Pin);
SolarGators::Drivers::Button horn         ("Horn", Horn_Button_GPIO_Port, Horn_Button_Pin);
SolarGators::Drivers::Button cruise       ("Cruise", Cruise_Button_GPIO_Port, Cruise_Button_Pin);
SolarGators::Drivers::Button reverse      ("Reverse", Reverse_Button_GPIO_Port, Reverse_Button_Pin, 3000);
// Leds
// Left Side
SolarGators::Drivers::LED lt_indicator    ("LT Indicator", LT_Led_GPIO_Port, LT_Led_Pin);
SolarGators::Drivers::LED eco_indicator   ("ECO Indicator", Eco_Led_GPIO_Port, Eco_Led_Pin);
SolarGators::Drivers::LED hl_indicator    ("HL Indicator", HL_Led_GPIO_Port, HL_Led_Pin);
// Right Side
SolarGators::Drivers::LED rt_indicator    ("RT Indicator", RT_Led_GPIO_Port, RT_Led_Pin);
SolarGators::Drivers::LED cr_indicator    ("CR Indicator", Cruise_Led_GPIO_Port, Cruise_Led_Pin);
SolarGators::Drivers::LED rev_indicator   ("Rev Indicator", Reverse_Led_GPIO_Port, Reverse_Led_Pin);

#endif
