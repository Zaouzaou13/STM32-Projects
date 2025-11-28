#include <DHT11.h>                // si tu as un fichier config
#include "main.h"                  // définitions des pins (Data_bus_Pin, Data_bus_GPIO_Port)
#include "stm32l4xx_hal.h"         // HAL global
#include "stm32l4xx_hal_tim.h"     // TIM HAL (optionnel si déjà inclus via stm32l4xx_hal.h)
#include <stdlib.h>



volatile uint32_t Val_Tab[50];
volatile uint32_t Val_Tab_Dec[5];
volatile uint32_t difference1[5];
volatile int STATE ;
volatile int FLAG_END_TRANSMISSION =0;
//variables
volatile int val_CC_1,val_CC_2;
volatile uint32_t Difference ;
volatile uint8_t i = 50;
volatile uint8_t FLAG_NBR_INT=0;
volatile uint8_t VAL_INCRMT = 4 ;

//Converting the periods of 26 us and 70us to 0 and 1 then checking the accuracy of the data recieved
uint8_t CHECK_DATA()
{
	volatile int k = 0 ;
	//converting the data from periods(26 or 70 us) to binary
	for (int i=49 ; i > 9 ; i--)
	{
		if ((20 < Val_Tab[i]) && (Val_Tab[i] < 30))
		{
			Val_Tab[i] = 0 ;
		}
		else
		{
			Val_Tab[i] = 1 ;
		}
	}
	//converting from binary to decimal
	for(int i=49 ; i>9 ;i-=8)
	{
		for (int j=0 ; j<8; j++)
		{
			Val_Tab_Dec[k] = (Val_Tab_Dec[k] << 1) | Val_Tab[i-j];
		}
		k++;
	}
	//checking accuracy with the checksum
	if(Val_Tab_Dec[0]+ Val_Tab_Dec[1]+Val_Tab_Dec[2]+Val_Tab_Dec[3] == Val_Tab_Dec[4])
	{
		FLAG_END_TRANSMISSION = 1;
		return 1 ; // transmission correcte

	}
	else
	{
		FLAG_END_TRANSMISSION = 1;
		return 0;
	}
}

//putting the GPIO of data_bus in output mode
void GPIO_DATA_BUS_OUTPUT()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = Data_bus_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

//generating a low signal of 18 ms for initialization
void CONFIG_START()
{
	HAL_GPIO_WritePin(Data_bus_GPIO_Port, Data_bus_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Data_bus_GPIO_Port, Data_bus_Pin, GPIO_PIN_RESET);
	HAL_Delay(20);
	HAL_GPIO_WritePin(Data_bus_GPIO_Port, Data_bus_Pin, GPIO_PIN_SET);

}

//putting the pin gpio Data_bus in input function (alterate function Open-Drain)
void GPIO_DATA_BUS_AF_OD()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = Data_bus_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = GPIO_AF1_TIM2; //modify this depending the number of timer chosen
	HAL_GPIO_Init(Data_bus_GPIO_Port, &GPIO_InitStruct);
}

//callback function for the timer interruption
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    //interruption flag incrementation
	FLAG_NBR_INT = FLAG_NBR_INT+1;
	val_CC_1 = HAL_TIM_ReadCapturedValue (htim, TIM_CHANNEL_4);

	//if the interruption flag that counts the number of interrupts occuring is equal to a certain value
	//that means that the period VAL_cc1-VAL_cc2 is either 26us or 70us
	if(FLAG_NBR_INT == VAL_INCRMT)
	{
		VAL_INCRMT +=2 ;
		if (val_CC_1 > val_CC_2 )
		{
			Difference = val_CC_1-val_CC_2;
		}
		else
		{
			Difference = val_CC_2-val_CC_1;
		}

		Val_Tab[i-1]= Difference;
		i = i-1 ;
	}

	val_CC_2 = val_CC_1;
    //if the interruption flag is equal to 83, that means that we had all the 40 bits sampled
	if(FLAG_NBR_INT == 83)
	{
		STATE = CHECK_DATA() ;
		FLAG_NBR_INT = 0;
		VAL_INCRMT = 4;
		i = 50;
	}
}





