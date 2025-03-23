//
// Created by jon on 2025/3/18.
//

#ifndef LVGL_UTILS_H
#define LVGL_UTILS_H

#include "custom.h"
#include "jansson.h"

#define CAM_DATA_CHANNEL "tabview_1_index1"
#define CAM_DATA_REQUEST_CHANNEL "cam_video_request"
#define CAM_DATA_FETCH_CHANNEL "cam_video_fetch"
#define CAM_WS_REQUEST_CHANNEL "cam_discovery_request"
#define CAM_WS_INFO_CHANNEL "cam_discovery_info"

void safe_set_textarea(lv_obj_t* textarea, const char* json_key, json_t* value);
const char* safe_get_json_string_value(const char* json_key, json_t* value);

#endif //LVGL_UTILS_H
