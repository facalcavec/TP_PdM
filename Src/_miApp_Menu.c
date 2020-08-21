/*
 * miApp_Menu_ppal.c
 *
 *  Created on: Aug 19, 2020
 *      Author: felipe
 */

#include <_miApp_Menu.h>
#include "stm32f1xx_hal.h"
#include "stm32_adafruit_lcd.h"

/* Función que muestra el menú inicial */
menuInit(){

	BSP_LCD_Clear(LCD_COLOR_BLACK);

	BSP_LCD_SetFont(&Font24);

	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
	BSP_LCD_DrawHLine(10,10, 460);
	BSP_LCD_DisplayStringAt(0, 25, "CARGADOR DE BATERIAS", CENTER_MODE);
	BSP_LCD_DrawHLine(10,60, 460);

	BSP_LCD_DisplayStringAt(0, 150, "20 AGOSTO 2020", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 190, "15:26:43", CENTER_MODE);
}

/* Función que muestra la cabecera del menú principal */
menuPrincipalCabecera( ){

	BSP_LCD_Clear(LCD_COLOR_BLACK);

	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
	BSP_LCD_DrawHLine(10,10, 460);
	BSP_LCD_DisplayStringAt(0, 25, "MENU PRINCIPAL", CENTER_MODE);
	BSP_LCD_DrawHLine(10,60, 460);
}

/* Función que muestra el menú principal */
menuPrincipal(uint8_t estadoMenu){

		BSP_LCD_SetFont(&Font24);

	if(estadoMenu == MENU_PPAL1){
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	}else{
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	}
	BSP_LCD_DisplayStringAt(40, 100, "1. ARRANQUE MANUAL/PAUSA", LEFT_MODE);

	if(estadoMenu == MENU_PPAL2){
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	}else{
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	}
	BSP_LCD_DisplayStringAt(40, 140, "2. REPORTES", LEFT_MODE);

	if(estadoMenu == MENU_PPAL3){
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	}else{
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	}
	BSP_LCD_DisplayStringAt(40, 180, "3. CONFIGURACION", LEFT_MODE);
}












