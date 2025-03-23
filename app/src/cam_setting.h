//
// Created by jon on 2025/3/18.
//

#ifndef LVGL_CAM_SETTING_H
#define LVGL_CAM_SETTING_H

#include "custom.h"
#include "jansson.h"
#include "pthread.h"

void fill_cam_setting(lv_ui_context *ui_context, json_t *root);
void show_cam_video_thread(lv_ui_context *ui_context, pthread_t *tid);

#endif //LVGL_CAM_SETTING_H
