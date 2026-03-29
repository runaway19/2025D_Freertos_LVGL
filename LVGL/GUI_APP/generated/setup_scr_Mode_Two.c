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



void setup_scr_Mode_Two(lv_ui *ui)
{
    //Write codes Mode_Two
    ui->Mode_Two = lv_obj_create(NULL);
    lv_obj_set_size(ui->Mode_Two, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Mode_Two, LV_SCROLLBAR_MODE_OFF);

    //Write style for Mode_Two, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Mode_Two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_Two_Mode_two
    ui->Mode_Two_Mode_two = lv_label_create(ui->Mode_Two);
    lv_label_set_text(ui->Mode_Two_Mode_two, "Single-Ended Mode");
    lv_label_set_long_mode(ui->Mode_Two_Mode_two, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_Two_Mode_two, 327, 34);
    lv_obj_set_size(ui->Mode_Two_Mode_two, 142, 39);

    //Write style for Mode_Two_Mode_two, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_Two_Mode_two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_Two_Mode_two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_Two_Mode_two, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_Two_Mode_two, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_Two_Mode_two, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_Two_Mode_two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_Two_Mode_two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_Two_Mode_two, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_Two_Mode_two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_Two_Mode_two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_Two_Mode_two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_Two_Mode_two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_Two_Mode_two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_Two_Mode_two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_Two_Change_Button
    ui->Mode_Two_Change_Button = lv_btn_create(ui->Mode_Two);
    ui->Mode_Two_Change_Button_label = lv_label_create(ui->Mode_Two_Change_Button);
    lv_label_set_text(ui->Mode_Two_Change_Button_label, "change");
    lv_label_set_long_mode(ui->Mode_Two_Change_Button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Mode_Two_Change_Button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Mode_Two_Change_Button, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Mode_Two_Change_Button_label, LV_PCT(100));
    lv_obj_set_pos(ui->Mode_Two_Change_Button, 350, 249);
    lv_obj_set_size(ui->Mode_Two_Change_Button, 100, 50);

    //Write style for Mode_Two_Change_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Mode_Two_Change_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Mode_Two_Change_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Mode_Two_Change_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Mode_Two_Change_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_Two_Change_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_Two_Change_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_Two_Change_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_Two_Change_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_Two_Change_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_Two_Change_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_Two_Start_Two
    ui->Mode_Two_Start_Two = lv_btn_create(ui->Mode_Two);
    ui->Mode_Two_Start_Two_label = lv_label_create(ui->Mode_Two_Start_Two);
    lv_label_set_text(ui->Mode_Two_Start_Two_label, "Start");
    lv_label_set_long_mode(ui->Mode_Two_Start_Two_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Mode_Two_Start_Two_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Mode_Two_Start_Two, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Mode_Two_Start_Two_label, LV_PCT(100));
    lv_obj_set_pos(ui->Mode_Two_Start_Two, 350, 151);
    lv_obj_set_size(ui->Mode_Two_Start_Two, 100, 50);

    //Write style for Mode_Two_Start_Two, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Mode_Two_Start_Two, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Mode_Two_Start_Two, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Mode_Two_Start_Two, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Mode_Two_Start_Two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_Two_Start_Two, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_Two_Start_Two, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_Two_Start_Two, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_Two_Start_Two, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_Two_Start_Two, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_Two_Start_Two, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_Two_Test_Line
    ui->Mode_Two_Test_Line = lv_label_create(ui->Mode_Two);
    lv_label_set_text(ui->Mode_Two_Test_Line, "Label");
    lv_label_set_long_mode(ui->Mode_Two_Test_Line, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_Two_Test_Line, 184, 154);
    lv_obj_set_size(ui->Mode_Two_Test_Line, 100, 32);

    //Write style for Mode_Two_Test_Line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_Two_Test_Line, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_Two_Test_Line, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_Two_Test_Line, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_Two_Test_Line, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_Two_Test_Line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_Two_Test_Line, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_Two_Test_Line, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_Two_Test_Line, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_Two_Test_Line, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_Two_Test_Line, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_Two_Test_Line, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_Two_Test_Line, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_Two_Test_Line, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_Two_Test_Line, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_Two_Test_Short
    ui->Mode_Two_Test_Short = lv_label_create(ui->Mode_Two);
    lv_label_set_text(ui->Mode_Two_Test_Short, "Label");
    lv_label_set_long_mode(ui->Mode_Two_Test_Short, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_Two_Test_Short, 184, 73);
    lv_obj_set_size(ui->Mode_Two_Test_Short, 100, 32);

    //Write style for Mode_Two_Test_Short, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_Two_Test_Short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_Two_Test_Short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_Two_Test_Short, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_Two_Test_Short, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_Two_Test_Short, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_Two_Test_Short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_Two_Test_Short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_Two_Test_Short, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_Two_Test_Short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_Two_Test_Short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_Two_Test_Short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_Two_Test_Short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_Two_Test_Short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_Two_Test_Short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_Two_label_1
    ui->Mode_Two_label_1 = lv_label_create(ui->Mode_Two);
    lv_label_set_text(ui->Mode_Two_label_1, "线长");
    lv_label_set_long_mode(ui->Mode_Two_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_Two_label_1, 42, 154);
    lv_obj_set_size(ui->Mode_Two_label_1, 114, 32);

    //Write style for Mode_Two_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_Two_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_Two_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_Two_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_Two_label_1, &lv_font_SourceHanSerifSC_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_Two_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_Two_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_Two_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_Two_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_Two_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_Two_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_Two_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_Two_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_Two_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_Two_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Mode_Two_label_2
    ui->Mode_Two_label_2 = lv_label_create(ui->Mode_Two);
    lv_label_set_text(ui->Mode_Two_label_2, "是否短路");
    lv_label_set_long_mode(ui->Mode_Two_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Mode_Two_label_2, 42, 73);
    lv_obj_set_size(ui->Mode_Two_label_2, 112, 27);

    //Write style for Mode_Two_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Mode_Two_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Mode_Two_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Mode_Two_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Mode_Two_label_2, &lv_font_SourceHanSerifSC_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Mode_Two_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Mode_Two_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Mode_Two_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Mode_Two_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Mode_Two_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Mode_Two_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Mode_Two_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Mode_Two_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Mode_Two_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Mode_Two_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Mode_Two.


    //Update current screen layout.
    lv_obj_update_layout(ui->Mode_Two);

    //Init events for screen.
    events_init_Mode_Two(ui);
}
