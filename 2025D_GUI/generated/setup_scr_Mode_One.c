/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_Mode_One(lv_ui *ui)
{
    //Write codes Mode_One
    ui->Mode_One = lv_obj_create(NULL);
    lv_obj_set_size(ui->Mode_One, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Mode_One, LV_SCROLLBAR_MODE_OFF);

    //Write style for Mode_One, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Mode_One, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_One_Change_Button
    ui->Mode_One_Change_Button = lv_btn_create(ui->Mode_One);
    ui->Mode_One_Change_Button_label = lv_label_create(ui->Mode_One_Change_Button);
    lv_label_set_text(ui->Mode_One_Change_Button_label, "change");
    lv_label_set_long_mode(ui->Mode_One_Change_Button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Mode_One_Change_Button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Mode_One_Change_Button, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Mode_One_Change_Button_label, LV_PCT(100));
    lv_obj_set_pos(ui->Mode_One_Change_Button, 350, 250);
    lv_obj_set_size(ui->Mode_One_Change_Button, 100, 50);

    //Write style for Mode_One_Change_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Mode_One_Change_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Mode_One_Change_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Mode_One_Change_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Mode_One_Change_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_One_Change_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_One_Change_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_One_Change_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_One_Change_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_One_Change_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_One_Change_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_One_name_1
    ui->Mode_One_name_1 = lv_label_create(ui->Mode_One);
    lv_label_set_text(ui->Mode_One_name_1, "Dual-ended Mode");
    lv_label_set_long_mode(ui->Mode_One_name_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_One_name_1, 318, 28);
    lv_obj_set_size(ui->Mode_One_name_1, 135, 43);

    //Write style for Mode_One_name_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_One_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_One_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_One_name_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_One_name_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_One_name_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_One_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_One_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_One_name_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_One_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_One_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_One_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_One_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_One_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_One_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_One_Test_Type
    ui->Mode_One_Test_Type = lv_label_create(ui->Mode_One);
    lv_label_set_text(ui->Mode_One_Test_Type, "Label");
    lv_label_set_long_mode(ui->Mode_One_Test_Type, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_One_Test_Type, 189, 71);
    lv_obj_set_size(ui->Mode_One_Test_Type, 124, 32);

    //Write style for Mode_One_Test_Type, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_One_Test_Type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_One_Test_Type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_One_Test_Type, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_One_Test_Type, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_One_Test_Type, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_One_Test_Type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_One_Test_Type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_One_Test_Type, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_One_Test_Type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_One_Test_Type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_One_Test_Type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_One_Test_Type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_One_Test_Type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_One_Test_Type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_One_Test_R
    ui->Mode_One_Test_R = lv_label_create(ui->Mode_One);
    lv_label_set_text(ui->Mode_One_Test_R, "Label");
    lv_label_set_long_mode(ui->Mode_One_Test_R, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_One_Test_R, 189, 150);
    lv_obj_set_size(ui->Mode_One_Test_R, 124, 32);

    //Write style for Mode_One_Test_R, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_One_Test_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_One_Test_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_One_Test_R, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_One_Test_R, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_One_Test_R, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_One_Test_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_One_Test_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_One_Test_R, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_One_Test_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_One_Test_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_One_Test_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_One_Test_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_One_Test_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_One_Test_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_One_Test_Db
    ui->Mode_One_Test_Db = lv_label_create(ui->Mode_One);
    lv_label_set_text(ui->Mode_One_Test_Db, "Label");
    lv_label_set_long_mode(ui->Mode_One_Test_Db, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_One_Test_Db, 188, 228);
    lv_obj_set_size(ui->Mode_One_Test_Db, 124, 32);

    //Write style for Mode_One_Test_Db, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_One_Test_Db, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_One_Test_Db, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_One_Test_Db, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_One_Test_Db, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_One_Test_Db, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_One_Test_Db, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_One_Test_Db, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_One_Test_Db, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_One_Test_Db, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_One_Test_Db, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_One_Test_Db, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_One_Test_Db, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_One_Test_Db, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_One_Test_Db, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_One_label_3
    ui->Mode_One_label_3 = lv_label_create(ui->Mode_One);
    lv_label_set_text(ui->Mode_One_label_3, "30MHz衰减");
    lv_label_set_long_mode(ui->Mode_One_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_One_label_3, 37, 232);
    lv_obj_set_size(ui->Mode_One_label_3, 126, 32);

    //Write style for Mode_One_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_One_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_One_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_One_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_One_label_3, &lv_font_SourceHanSerifSC_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_One_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_One_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_One_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_One_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_One_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_One_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_One_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_One_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_One_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_One_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_One_label_2
    ui->Mode_One_label_2 = lv_label_create(ui->Mode_One);
    lv_label_set_text(ui->Mode_One_label_2, "R");
    lv_label_set_long_mode(ui->Mode_One_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_One_label_2, 51, 150);
    lv_obj_set_size(ui->Mode_One_label_2, 100, 32);

    //Write style for Mode_One_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_One_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_One_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_One_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_One_label_2, &lv_font_SourceHanSerifSC_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_One_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_One_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_One_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_One_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_One_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_One_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_One_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_One_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_One_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_One_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_One_label_1
    ui->Mode_One_label_1 = lv_label_create(ui->Mode_One);
    lv_label_set_text(ui->Mode_One_label_1, "类型");
    lv_label_set_long_mode(ui->Mode_One_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_One_label_1, 51, 71);
    lv_obj_set_size(ui->Mode_One_label_1, 100, 32);

    //Write style for Mode_One_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_One_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_One_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_One_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_One_label_1, &lv_font_SourceHanSerifSC_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_One_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_One_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_One_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_One_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_One_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_One_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_One_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_One_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_One_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_One_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_One_Start_One
    ui->Mode_One_Start_One = lv_btn_create(ui->Mode_One);
    ui->Mode_One_Start_One_label = lv_label_create(ui->Mode_One_Start_One);
    lv_label_set_text(ui->Mode_One_Start_One_label, "Start");
    lv_label_set_long_mode(ui->Mode_One_Start_One_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Mode_One_Start_One_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Mode_One_Start_One, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Mode_One_Start_One_label, LV_PCT(100));
    lv_obj_set_pos(ui->Mode_One_Start_One, 350, 150);
    lv_obj_set_size(ui->Mode_One_Start_One, 100, 50);

    //Write style for Mode_One_Start_One, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Mode_One_Start_One, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Mode_One_Start_One, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Mode_One_Start_One, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Mode_One_Start_One, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_One_Start_One, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_One_Start_One, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_One_Start_One, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_One_Start_One, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_One_Start_One, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_One_Start_One, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Mode_One.


    //Update current screen layout.
    lv_obj_update_layout(ui->Mode_One);

    //Init events for screen.
    events_init_Mode_One(ui);
}
