#include "my_lvgl.h"

void init_lvgl()
{
	  // LVGL自带示例程序
	//  lv_demo_widgets();
	//  lv_demo_stress();
	//  lv_demo_benchmark();
	//	lv_demo_music();
	
	  USART1_Printf("%d : Run LVGL_TaskHandler_Task\r\n", osKernelSysTick());
		lv_init(); 							// LVGL初始
		USART1_Printf("%d : lv_init() Finish\r\n", osKernelSysTick());
		lv_port_disp_init(); 		// LVGL显示初始
		USART1_Printf("%d : lv_port_disp_init() Finish\r\n", osKernelSysTick());
		LCD_Switch_Dir(3); 			// 旋转屏幕方向
		USART1_Printf("%d : LCD_Switch_Dir(0) Finish\r\n", osKernelSysTick());
	
		USART1_Printf("%d : LCD ID:%d\r\n", osKernelSysTick(), LCD_Read_ID());
	
	    // 按钮
    lv_obj_t *myBtn = lv_btn_create(lv_scr_act());                               // 创建按钮; 父对象：当前活动屏幕
    lv_obj_set_pos(myBtn, 10, 10);                                               // 设置坐标
    lv_obj_set_size(myBtn, 120, 50);                                             // 设置大小
   
    // 按钮上的文本
    lv_obj_t *label_btn = lv_label_create(myBtn);                                // 创建文本标签，父对象：上面的btn按钮
    lv_obj_align(label_btn, LV_ALIGN_CENTER, 0, 0);                              // 对齐于：父对象
    lv_label_set_text(label_btn, "Test");                                        // 设置标签的文本
 
    // 独立的标签
    lv_obj_t *myLabel = lv_label_create(lv_scr_act());                           // 创建文本标签; 父对象：当前活动屏幕
    lv_label_set_text(myLabel, "Hello world!");                                  // 设置标签的文本
    lv_obj_align(myLabel, LV_ALIGN_CENTER, 0, 0);                                // 对齐于：父对象
    lv_obj_align_to(myBtn, myLabel, LV_ALIGN_OUT_TOP_MID, 0, -20);               // 对齐于：某对象

}


