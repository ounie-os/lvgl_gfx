//
// Created by jon on 2025/3/23.
//

#ifndef LVGL_GFX_MASTER_CAM_VIDEO_H
#define LVGL_GFX_MASTER_CAM_VIDEO_H
#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
extern "C" {
#endif

#include "custom.h"
#include "jansson.h"
#include "utils.h"
void receive_and_display_image(void *arg);

#ifdef __cplusplus
}
#endif

#endif //LVGL_GFX_MASTER_CAM_VIDEO_H
