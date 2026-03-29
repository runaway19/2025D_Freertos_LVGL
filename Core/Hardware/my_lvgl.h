#ifndef __MY_LVGL_H
#define __MY_LVGL_H

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

