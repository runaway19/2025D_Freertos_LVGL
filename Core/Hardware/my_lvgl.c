#include "my_lvgl.h"

lv_ui guider_ui;//GUI结构体定义

void init_lvgl()
{
	  USART1_Printf("%d : Run LVGL_TaskHandler_Task\r\n", osKernelSysTick());
		lv_init(); 							// LVGL初始
		USART1_Printf("%d : lv_init() Finish\r\n", osKernelSysTick());
		lv_port_disp_init(); 		// LVGL显示初始
		USART1_Printf("%d : lv_port_disp_init() Finish\r\n", osKernelSysTick());
		LCD_Switch_Dir(3); 			// 旋转屏幕方向
		USART1_Printf("%d : LCD_Switch_Dir(0) Finish\r\n", osKernelSysTick());
	
		USART1_Printf("%d : LCD ID:%d\r\n", osKernelSysTick(), LCD_Read_ID());
	
	
	  /*LV_SPRINTF_USE_FLOAT开启打印浮点数*/
		custom_init(&guider_ui);//变量初始化
		setup_ui(&guider_ui);//GUI初始化
		events_init(&guider_ui);//GUI事件初始化
	
}

