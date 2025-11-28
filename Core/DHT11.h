#include "stm32l4xx_hal.h"         // HAL global
#include "stm32l4xx_hal_tim.h"     // TIM HAL (optionnel si déjà inclus via stm32l4xx_hal.h)

//fonction qui sert à mettre la pin GPIO Data_bus en mode output
void GPIO_DATA_BUS_OUTPUT();
//fonction qui génère une pulsion à l'état bas durant 18ms
void CONFIG_START();
//fonction qui sert à mettre la pin GPIO Data_bus en mode alternate function OD
void GPIO_DATA_BUS_AF_OD();
uint8_t CHECK_DATA();
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) ;
