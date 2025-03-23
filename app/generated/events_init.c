/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include "lvgl.h"
#include "custom.h"
#include "events_cb.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_imgbtn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = e->user_data;
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        lv_disp_load_scr(ui->screen_1);
        break;
    }
    default:
        break;
    }
}

void events_init_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_imgbtn_1, screen_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_1_ddlist_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui_context *ui_context = e->user_data;
    switch (code) {
        case LV_EVENT_VALUE_CHANGED:
        {
            screen_1_ddlist_1_cb(ui_context);
            break;
        }
        default:
            break;
    }
}

static void screen_1_sw_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui_context *ui_context = e->user_data;
    switch (code) {
        case LV_EVENT_VALUE_CHANGED:
        {
            lv_obj_t * status_obj = lv_event_get_target(e);
            int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
            screen_1_sw_1_cb(ui_context, status);
            break;
        }
        default:
            break;
    }
}

static void screen_1_tabview_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui_context *ui_context = e->user_data;
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        screen_1_tabview_1_cb(ui_context);
        break;
    }
    default:
        break;
    }
}

static void screen_1_btn_19_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui_context *ui_context = e->user_data;
    switch (code) {
        case LV_EVENT_RELEASED:
        {
            screen_1_btn_19_cb(ui_context);
            break;
        }
        default:
            break;
    }
}

static void screen_1_btn_21_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui_context *ui_context = e->user_data;
    switch (code) {
        case LV_EVENT_RELEASED:
        {
            screen_1_btn_21_cb(ui_context);
            break;
        }
        default:
            break;
    }
}


static void screen_1_imgbtn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = e->user_data;
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        lv_obj_add_flag(ui->screen_1_cont_7, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui->screen_1_cont_8, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}
static void screen_1_btn_25_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = e->user_data;
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        lv_obj_clear_flag(ui->screen_1_cont_7, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui->screen_1_cont_8, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}
static void screen_1_imgbtn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = e->user_data;
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        lv_disp_load_scr(ui->screen);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_1_tabview_1, screen_1_tabview_1_event_handler, LV_EVENT_VALUE_CHANGED, &g_lv_ui_context);
    lv_obj_add_event_cb(ui->screen_1_sw_1, screen_1_sw_1_event_handler, LV_EVENT_VALUE_CHANGED, &g_lv_ui_context);
    lv_obj_add_event_cb(ui->screen_1_ddlist_1, screen_1_ddlist_1_event_handler, LV_EVENT_ALL, &g_lv_ui_context);
    lv_obj_add_event_cb(ui->screen_1_btn_19, screen_1_btn_19_event_handler, LV_EVENT_ALL, &g_lv_ui_context);
    lv_obj_add_event_cb(ui->screen_1_btn_21, screen_1_btn_21_event_handler, LV_EVENT_ALL, &g_lv_ui_context);
    lv_obj_add_event_cb(ui->screen_1_imgbtn_2, screen_1_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_btn_25, screen_1_btn_25_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_imgbtn_1, screen_1_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
