/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "events_cb.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

lv_ui_context g_lv_ui_context;
/**
 * Create a demo application
 */

redisContext* init_redis_context() {
    redisContext *c = init_redis("127.0.0.1", 6379);
    if (c != NULL) {
        return c;
//        int ret = auth_redis(c, "ounie@redis");
//        if (ret == 0) {
//            printf("auth redis success\n");
//            return c;
//        }
    }
    return NULL;
}

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    setup_scr_screen_1(ui);
    redisContext *c_pub = init_redis_context();
    redisContext *c_sub = init_redis_context();
    if ((c_pub != NULL) && (c_sub != NULL)) {
        g_lv_ui_context.c_pub = c_pub;
        g_lv_ui_context.c_sub = c_sub;
        subscribe_init(&g_lv_ui_context);
    }
}

