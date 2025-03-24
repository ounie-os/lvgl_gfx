//
// Created by jon on 2025/3/23.
//

#include "cam_video.h"
#include <string>
#include <iostream>
#include <unistd.h>
//#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;


static void update_canvas_task(lv_timer_t *timer) {
    lv_ui_context *ui_context = (lv_ui_context *)timer->user_data;
    const char *image_data = ui_context->image_data;
    size_t image_size = ui_context->image_size;

    if (image_data && image_size > 0) {
//        lv_log("%llu\n", image_size);
//        lv_draw_img_dsc_t img_dst;
//        img_dst.opa = LV_OPA_100;
        lv_canvas_set_buffer(ui_context->ui->screen_1_canvas_1, (void *)ui_context->image_data, 320, 240, LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED);
//        lv_canvas_draw_img(ui_context->ui->screen_1_canvas_1, 0, 0, image_data, &img_dst);
//        lv_img_set_src(ui_context->ui->screen_1_img_1, image_data);
    }
}

void receive_and_display_image(void *arg) {
    redisReply *reply;
    lv_ui_context *ui_context = (lv_ui_context *)arg;
    redisContext *redis_ctx = init_redis_context();
    if (NULL == redis_ctx) {
        lv_log("receive_and_display_image redis_ctx is null\n");
        return;
    }
    ui_context->image_data = (char*)lv_mem_alloc(640 * 480 * 4);
    VideoCapture cap;
    Mat frame;
    const char *rtsp_url;
    subscribe_redis(redis_ctx, CAM_DATA_FETCH_CHANNEL);
    if (REDIS_OK == redisGetReply(redis_ctx, (void **)&reply)) {
        if ((reply->type == REDIS_REPLY_ARRAY) && (reply->elements == 3)) {
            rtsp_url = reply->element[2]->str;
            cap.open(rtsp_url);
            if (!cap.isOpened()) {
                cerr << "ERROR! Unable to open camera\n";
                return;
            }
        }
    }
    lv_log("receive_and_display_image thread begin: %s\n", rtsp_url);
    std::vector<uchar> pngData;
    while (ui_context->image_run) {
        cap.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            usleep(500000);
            continue;
        }

        cv::imencode(".png", frame, pngData);
        char* pngBytes = reinterpret_cast<char*>(pngData.data());
        size_t pngSize = pngData.size();
        lv_log("png size=%d\n", pngSize);
        lv_memcpy(ui_context->image_data, pngBytes, pngSize);
        lv_timer_t *timer = lv_timer_create(update_canvas_task, 10, ui_context);
        lv_timer_set_repeat_count(timer, 1); // 只执行一次
        usleep(50000);
    }
    lv_mem_free(ui_context->image_data);
    cap.release();
    unsubscribe_redis(redis_ctx, CAM_DATA_FETCH_CHANNEL);
    redisFree(redis_ctx);
    lv_log("receive_and_display_image thread end\n");
}
