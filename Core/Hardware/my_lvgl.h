#ifndef __MY_LVGL_H
#define __MY_LVGL_H

/*
 ******************************************************************************
 *    Ó²¼þ½ÓÏß  LVGL
 *    LCD                   
 * ----------------------------------------------------------------------------
 *    GND       ->      GND         
 *    VCC       ->      5V        
 *    LCD_CS    ->      PE6       
 *    LCD_RST   ->      PC1       
 *    LCD_RS    ->      PC0       
 *    SDI(MOSI) ->      PB5       
 *    SCK       ->      PB3       
 *    LED       ->      3.3V
 *    SDO(MISO) ->      PB4       
 *    CTP_SCL   ->      PB8       
 *    CTP_RST   ->      PB7       
 *    CTP_SDA   ->      PB9       
 *    CTP_INT   ->      PB6       
 ****************************************************************************** 
 */
 
 
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "LCD.h"
#include "touch.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "usart.h"
#include "../generated/gui_guider.h"
#include "../generated/events_init.h"
#include "custom.h"
#include "my_fun.h"
#include <stdio.h>

extern lv_ui guider_ui;

void init_lvgl(void);
void change_label_mode_one(void);
void change_label_mode_two(void);
	
#endif

