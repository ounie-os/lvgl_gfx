/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

#include "hiredis.h"

#include "redis_lib.h"

typedef struct {
    lv_ui *ui;
    redisContext *c_pub;
    redisContext *c_sub;
    char *image_data;
    size_t image_size;
    size_t image_run;
}lv_ui_context;

void custom_init(lv_ui *ui);
redisContext* init_redis_context();

extern lv_ui_context g_lv_ui_context;

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
