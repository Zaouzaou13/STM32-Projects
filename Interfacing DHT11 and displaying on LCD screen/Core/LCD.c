#include "LCD.h"
#include "main.h"                  // définitions des pins (Data_bus_Pin, Data_bus_GPIO_Port)
#include "stm32l4xx_hal.h"         // HAL global

extern uint32_t Val_Tab_Dec[5];

void INIT_FUNCTION()
{
	//RS
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//Data Pins
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_RESET);
	//Enable pin
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}

void FUNCTION_SET()
{
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//Enable pin
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}

void DISPLAY_OFF()
{
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//Enable pin
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}

void DISPLAY_CLEAR()
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
	//HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	//Enable pin
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
}

void ENTRY_MODE_SET()
{
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//Enable pin
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}

void INIT_LCD()
{
	INIT_FUNCTION();
	HAL_Delay(5);
    INIT_FUNCTION();
	HAL_Delay(1);
	INIT_FUNCTION();
	HAL_Delay(1);
	FUNCTION_SET();
	HAL_Delay(1);
	DISPLAY_OFF();
	HAL_Delay(1);
	DISPLAY_CLEAR();
	HAL_Delay(2);
	ENTRY_MODE_SET();
	HAL_Delay(1);
}

void WRITE_ADRESS_DDRAM(uint8_t addr)
{
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
	//writing adress
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, ((addr >> 6) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, ((addr >> 5) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, ((addr >> 4) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, ((addr >> 3) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, ((addr >> 2) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, ((addr >> 1) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, ((addr >> 0) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_Delay(1);
	//Enable pin
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}

void WRITE_SYMBOL(uint8_t addr)
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);
	//HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//writing symbol address
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, ((addr >> 7) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, ((addr >> 6) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, ((addr >> 5) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, ((addr >> 4) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, ((addr >> 3) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, ((addr >> 2) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, ((addr >> 1) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, ((addr >> 0) & 1 ) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	//Enable pin
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}

void WRITE_INIT_FIRST()
{
	//écrire un S
	WRITE_ADRESS_DDRAM(0x00);
	HAL_Delay(1);
	WRITE_SYMBOL(0x53);
	HAL_Delay(1);
	//écrire un T
	WRITE_ADRESS_DDRAM(0x01);
	HAL_Delay(1);
	WRITE_SYMBOL(0x54);
	HAL_Delay(1);
	//écrire un A
	WRITE_ADRESS_DDRAM(0x02);
	HAL_Delay(1);
	WRITE_SYMBOL(0x41);
	HAL_Delay(1);
	//écrire un T
	WRITE_ADRESS_DDRAM(0x03);
	HAL_Delay(1);
	WRITE_SYMBOL(0x54);
	HAL_Delay(1);
	//écrire un I
	WRITE_ADRESS_DDRAM(0x04);
	HAL_Delay(1);
	WRITE_SYMBOL(0x7C);
	HAL_Delay(1);
	//écrire un O
	WRITE_ADRESS_DDRAM(0x05);
	HAL_Delay(1);
	WRITE_SYMBOL(0x4F);
	HAL_Delay(1);
	//écrire un N
	WRITE_ADRESS_DDRAM(0x06);
	HAL_Delay(1);
	WRITE_SYMBOL(0x4E);
	HAL_Delay(1);
	//écrire Un M
	WRITE_ADRESS_DDRAM(0x09);
	HAL_Delay(1);
	WRITE_SYMBOL(0x4D);
	HAL_Delay(1);
	//écrire Un E
	WRITE_ADRESS_DDRAM(0x0A);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
	//écrire Un T
	WRITE_ADRESS_DDRAM(0x0B);
	HAL_Delay(1);
	WRITE_SYMBOL(0x54);
	HAL_Delay(1);
	//écrire Un E
	WRITE_ADRESS_DDRAM(0x0C);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
	//écrire un O
	WRITE_ADRESS_DDRAM(0x0D);
	HAL_Delay(1);
	WRITE_SYMBOL(0x4F);
	HAL_Delay(1);
	//écrire un B
	WRITE_ADRESS_DDRAM(0x43);
	HAL_Delay(1);
	WRITE_SYMBOL(0x42);
	HAL_Delay(1);
	//écrire un I
	WRITE_ADRESS_DDRAM(0x44);
	HAL_Delay(1);
	WRITE_SYMBOL(0x7C);
	HAL_Delay(1);
	//écrire un E
	WRITE_ADRESS_DDRAM(0x45);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
	//écrire un N
	WRITE_ADRESS_DDRAM(0x46);
	HAL_Delay(1);
	WRITE_SYMBOL(0x4E);
	HAL_Delay(1);
	//écrire un V
	WRITE_ADRESS_DDRAM(0x47);
	HAL_Delay(1);
	WRITE_SYMBOL(0x56);
	HAL_Delay(1);
	//écrire un E
	WRITE_ADRESS_DDRAM(0x48);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
	//écrire un N
	WRITE_ADRESS_DDRAM(0x49);
	HAL_Delay(1);
	WRITE_SYMBOL(0x4E);
	HAL_Delay(1);
	//écrire un U
	WRITE_ADRESS_DDRAM(0x4A);
	HAL_Delay(1);
	WRITE_SYMBOL(0x55);
	HAL_Delay(1);
	//écrire un E
	WRITE_ADRESS_DDRAM(0x4B);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
}

void WRITE_REQUETE()
{
	//écrire un R
	WRITE_ADRESS_DDRAM(0x43);
	HAL_Delay(1);
	WRITE_SYMBOL(0x52);
	HAL_Delay(1);
	//Ecrire un E
	WRITE_ADRESS_DDRAM(0x44);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
	//Ecrire un Q
	WRITE_ADRESS_DDRAM(0x45);
	HAL_Delay(1);
	WRITE_SYMBOL(0x51);
	HAL_Delay(1);
	//Ecrire un U
	WRITE_ADRESS_DDRAM(0x46);
	HAL_Delay(1);
	WRITE_SYMBOL(0x55);
	HAL_Delay(1);
	//Ecrire un E
	WRITE_ADRESS_DDRAM(0x47);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
	//Ecrire un T
	WRITE_ADRESS_DDRAM(0x48);
	HAL_Delay(1);
	WRITE_SYMBOL(0x54);
	HAL_Delay(1);
	//Ecrire un E
	WRITE_ADRESS_DDRAM(0x49);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
	//Ecrire un .
	WRITE_ADRESS_DDRAM(0x4A);
	HAL_Delay(1);
	WRITE_SYMBOL(0x2E);
	HAL_Delay(1);
	//Ecrire un .
	WRITE_ADRESS_DDRAM(0x4B);
	HAL_Delay(1);
	WRITE_SYMBOL(0x2E);
	HAL_Delay(1);
	//Ecrire un .
	WRITE_ADRESS_DDRAM(0x4C);
	HAL_Delay(1);
	WRITE_SYMBOL(0x2E);
	HAL_Delay(1);
}

void WRITE_ERROR()
{
	//Ecrire un E
	WRITE_ADRESS_DDRAM(0x44);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
	//écrire un R
	WRITE_ADRESS_DDRAM(0x45);
	HAL_Delay(1);
	WRITE_SYMBOL(0x52);
	HAL_Delay(1);
	//écrire un R
	WRITE_ADRESS_DDRAM(0x46);
	HAL_Delay(1);
	WRITE_SYMBOL(0x52);
	HAL_Delay(1);
	//Ecrire un E
	WRITE_ADRESS_DDRAM(0x47);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
	//Ecrire un U
	WRITE_ADRESS_DDRAM(0x48);
	HAL_Delay(1);
	WRITE_SYMBOL(0x55);
	HAL_Delay(1);
	//écrire un R
	WRITE_ADRESS_DDRAM(0x49);
	HAL_Delay(1);
	WRITE_SYMBOL(0x52);
	HAL_Delay(1);
}

void WRITE_TEMP_HUM()
{
	uint8_t unite, dizaine ;
	unite = Val_Tab_Dec[2] % 10 ;
	dizaine = Val_Tab_Dec[2] / 10 ;
	uint8_t addr;
	addr = 3 << 4 ;


	//température
	//écrire un T
	WRITE_ADRESS_DDRAM(0x00);
	HAL_Delay(1);
	WRITE_SYMBOL(0x54);
	HAL_Delay(1);
	//écrire un E
	WRITE_ADRESS_DDRAM(0x01);
	HAL_Delay(1);
	WRITE_SYMBOL(0x45);
	HAL_Delay(1);
	//écrire un M
	WRITE_ADRESS_DDRAM(0x02);
	HAL_Delay(1);
	WRITE_SYMBOL(0x4D);
	HAL_Delay(1);
	//écrire un P
	WRITE_ADRESS_DDRAM(0x03);
	HAL_Delay(1);
	WRITE_SYMBOL(0x50);
	HAL_Delay(1);
	//écrire un espace
	WRITE_ADRESS_DDRAM(0x04);
	HAL_Delay(1);
	WRITE_SYMBOL(0x10);
	HAL_Delay(1);
	//écrire la dizaine
	addr = addr | dizaine ;
	WRITE_ADRESS_DDRAM(0x05);
	HAL_Delay(1);
	WRITE_SYMBOL(addr);
	HAL_Delay(1);

	//écrire l'unité
	addr = 3 << 4 ;
	addr = addr | unite ;
	WRITE_ADRESS_DDRAM(0x06);
	HAL_Delay(1);
	WRITE_SYMBOL(addr);
	HAL_Delay(1);
	//écrire le point
	WRITE_ADRESS_DDRAM(0x07);
	HAL_Delay(1);
	WRITE_SYMBOL(0xDF);
	HAL_Delay(1);
	//écrire le C du Celsius
	WRITE_ADRESS_DDRAM(0x08);
	HAL_Delay(1);
	WRITE_SYMBOL(0x43);
	HAL_Delay(1);

	//Humidité
	unite = Val_Tab_Dec[0] % 10 ;
	dizaine = Val_Tab_Dec[0] / 10 ;

	//écrire un H
	WRITE_ADRESS_DDRAM(0x40);
	HAL_Delay(1);
	WRITE_SYMBOL(0x48);
	HAL_Delay(1);
	//écrire un U
	WRITE_ADRESS_DDRAM(0x41);
	HAL_Delay(1);
	WRITE_SYMBOL(0x55);
	HAL_Delay(1);
	//écrire un M
	WRITE_ADRESS_DDRAM(0x42);
	HAL_Delay(1);
	WRITE_SYMBOL(0x4D);
	HAL_Delay(1);
	//écrire un espace
	WRITE_ADRESS_DDRAM(0x43);
	HAL_Delay(1);
	WRITE_SYMBOL(0x10);
	HAL_Delay(1);
	//écrire un espace
	WRITE_ADRESS_DDRAM(0x44);
	HAL_Delay(1);
	WRITE_SYMBOL(0x10);
	HAL_Delay(1);
	addr = 3 << 4 ;
	//écrire la dizaine
	addr = addr | dizaine ;
	WRITE_ADRESS_DDRAM(0x45);
	HAL_Delay(1);
	WRITE_SYMBOL(addr);
	HAL_Delay(1);

	//écrire l'unité
	addr = 3 << 4 ;
	addr = addr | unite ;
	WRITE_ADRESS_DDRAM(0x46);
	HAL_Delay(1);
	WRITE_SYMBOL(addr);
	HAL_Delay(1);
    //écrire le pourcentage
	WRITE_ADRESS_DDRAM(0x48);
	HAL_Delay(1);
	WRITE_SYMBOL(0x25);
	HAL_Delay(1);
}
