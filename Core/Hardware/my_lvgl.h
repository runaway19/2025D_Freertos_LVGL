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

void init_lvgl(void);
	
#endif

