/**
 *
 * This file is created and owned by anyui.
 *
 * Version: 0.40.1
 *
 * COPYRIGHT 2026 anyui Team
 * All rights reserved.
 *
 * https://anyui.tech/
 *
 * Author: anyui Team
 */

#include "anyui_ui.h"


lv_obj_t * screen_1 = NULL;
lv_obj_t * screen_1_btn_I8Gulgey = NULL;
lv_obj_t * screen_1_btn_I8Gulgey_label = NULL;
lv_obj_t * screen_1_btn_so2ZvDSs = NULL;
lv_obj_t * screen_1_btn_so2ZvDSs_label = NULL;
static event_table_t screen_1_event_table = {0};
static void register_sys_events(event_table_t *table);
static void init_states(void);
static void register_ui_events(void);
static lv_obj_t * create_ui(void);


static void register_sys_events(event_table_t *table) {
}
static void init_states(void) {
    extern lv_obj_t * global_statusbar;
    set_current_event_table(&screen_1_event_table);
}
static void register_ui_events(void) {
}
static lv_obj_t * create_ui(void) {
    LV_LOG_USER("Initializing screen_1 ...");
    screen_1 = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(screen_1, LV_SCROLLBAR_MODE_OFF);
    // Create screen_1_btn_I8Gulgey
    screen_1_btn_I8Gulgey = lv_btn_create(screen_1);
    lv_obj_set_x(screen_1_btn_I8Gulgey, 352);
    lv_obj_set_y(screen_1_btn_I8Gulgey, 242);
    lv_obj_set_width(screen_1_btn_I8Gulgey, 100);
    lv_obj_set_height(screen_1_btn_I8Gulgey, 50);
    screen_1_btn_I8Gulgey_label = lv_label_create(screen_1_btn_I8Gulgey);
    lv_obj_set_scrollbar_mode(screen_1_btn_I8Gulgey, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(screen_1_btn_I8Gulgey_label, "切换");
    lv_obj_set_style_pad_all(screen_1_btn_I8Gulgey, 0, LV_STATE_DEFAULT);
    lv_obj_align(screen_1_btn_I8Gulgey_label, LV_ALIGN_CENTER, 0, 0);
    // Add style for screen_1_btn_I8Gulgey - LV_PART_MAIN | LV_STATE_DEFAULT
    lv_obj_set_style_text_color(screen_1_btn_I8Gulgey, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(screen_1_btn_I8Gulgey, &lv_font_SourceHanSansSC_Normal_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(screen_1_btn_I8Gulgey, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // Create screen_1_btn_so2ZvDSs
    screen_1_btn_so2ZvDSs = lv_btn_create(screen_1);
    lv_obj_set_x(screen_1_btn_so2ZvDSs, 180);
    lv_obj_set_y(screen_1_btn_so2ZvDSs, 75);
    lv_obj_set_width(screen_1_btn_so2ZvDSs, 100);
    lv_obj_set_height(screen_1_btn_so2ZvDSs, 50);
    screen_1_btn_so2ZvDSs_label = lv_label_create(screen_1_btn_so2ZvDSs);
    lv_obj_set_scrollbar_mode(screen_1_btn_so2ZvDSs, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(screen_1_btn_so2ZvDSs_label, "Button");
    lv_obj_set_style_pad_all(screen_1_btn_so2ZvDSs, 0, LV_STATE_DEFAULT);
    lv_obj_align(screen_1_btn_so2ZvDSs_label, LV_ALIGN_CENTER, 0, 0);
    // Add style for screen_1_btn_so2ZvDSs - LV_PART_MAIN | LV_STATE_DEFAULT
    lv_obj_set_style_text_color(screen_1_btn_so2ZvDSs, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(screen_1_btn_so2ZvDSs, &lv_font_SourceHanSansSC_Normal_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(screen_1_btn_so2ZvDSs, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    return screen_1;
}
lv_obj_t * setup_screen_1(void) {
    if (screen_1 != NULL) {
        init_states();
        return screen_1;
    }
    create_ui();
    register_ui_events();
    register_sys_events(&screen_1_event_table);
    init_states();
    return screen_1;
}
