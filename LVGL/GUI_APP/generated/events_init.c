/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "stdint.h"
#include "stdio.h"

// 这里的宏判断是关键：
// 如果是在 Windows/MinGW 仿真环境
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
uint8_t start_mode = 0; // 仿真器自己定义一个，防止链接报错
#else
extern uint8_t start_mode; // 真正的 STM32 环境，引用外部变量
#endif
#include "stdint.h"
#include "stdio.h"

// 仅仅声明，不定义（不给它分配空间，就不会重复）
extern uint8_t start_mode;

static void Mode_One_Change_Button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Mode_Two, guider_ui.Mode_Two_del, &guider_ui.Mode_One_del, setup_scr_Mode_Two, LV_SCR_LOAD_ANIM_NONE, 20, 20, false, false);
        break;
    }
    default:
        break;
    }
}

static void Mode_One_Start_One_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        start_mode = 1;

        break;
    }
    default:
        break;
    }
}

void events_init_Mode_One (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Mode_One_Change_Button, Mode_One_Change_Button_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Mode_One_Start_One, Mode_One_Start_One_event_handler, LV_EVENT_ALL, ui);
}

static void Mode_Two_Change_Button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Mode_One, guider_ui.Mode_One_del, &guider_ui.Mode_Two_del, setup_scr_Mode_One, LV_SCR_LOAD_ANIM_NONE, 20, 20, false, false);
        break;
    }
    default:
        break;
    }
}

static void Mode_Two_Start_Two_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        start_mode = 2;



        break;
    }
    default:
        break;
    }
}

void events_init_Mode_Two (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Mode_Two_Change_Button, Mode_Two_Change_Button_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Mode_Two_Start_Two, Mode_Two_Start_Two_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
