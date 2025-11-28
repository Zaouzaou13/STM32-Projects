
#include "stm32l4xx_hal.h"         // HAL global
#include "stm32l4xx_hal_tim.h"     // TIM HAL (optionnel si déjà inclus via stm32l4xx_hal.h)


//fonction d'initialisation pour choisir le mode 8 bits
void INIT_FUNCTION();
//fonction d'initialisation pour choisir le mode 2 lignes et taille 5*8
void FUNCTION_SET();
//fonction d'initialisation pour éteindre l'écran
void DISPLAY_OFF();
//fonction d'initialisation pour supprimer tout ce qui s'afffiche sur l'écran, suprrimer le contenu
//dans la mémoire et initialiser le curseur
void DISPLAY_CLEAR();
//fonction d'initialisation pour choisir la direction du curseur et le défilement
void ENTRY_MODE_SET();
//fonction d'initialisation de l'écran LCD
void INIT_LCD();
//cette fonction écrit l'adresse de la DDRAM
void WRITE_ADRESS_DDRAM(uint8_t addr);
//cette fonction écrit l'adresse du symbole à écrire
void WRITE_SYMBOL(uint8_t addr);
void WRITE_INIT_FIRST();
void WRITE_REQUETE();
void WRITE_ERROR() ;
void WRITE_TEMP_HUM();
