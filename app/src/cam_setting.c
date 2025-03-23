//
// Created by jon on 2025/3/18.
//

#include "cam_setting.h"
#include "utils.h"
#include "pthread.h"
#include "custom.h"
#include <signal.h>

void fill_cam_setting(lv_ui_context *ui_context, json_t *root) {
    if (json_is_array(root)) {
        size_t index;
        json_t *value;
        lv_dropdown_clear_options(ui_context->ui->screen_1_ddlist_1);
        json_array_foreach(root, index, value) {
            if (index == 0) {
                // 调用封装函数
                safe_set_textarea(ui_context->ui->screen_1_ta_38, "ip", value);
                safe_set_textarea(ui_context->ui->screen_1_ta_39, "port", value);
                safe_set_textarea(ui_context->ui->screen_1_ta_40, "username", value);
                safe_set_textarea(ui_context->ui->screen_1_ta_41, "passwd", value);
                lv_dropdown_set_selected(ui_context->ui->screen_1_ddlist_2, json_integer_value(json_object_get(value, "ptz_speed")) - 1);
            }
            lv_dropdown_add_option(ui_context->ui->screen_1_ddlist_1, json_string_value(json_object_get(value, "cam_no")), -1);
        }
        lv_dropdown_set_selected(ui_context->ui->screen_1_ddlist_1, 0);
    } else {
        safe_set_textarea(ui_context->ui->screen_1_ta_38, "ip", root);
        safe_set_textarea(ui_context->ui->screen_1_ta_39, "port", root);
        safe_set_textarea(ui_context->ui->screen_1_ta_40, "username", root);
        safe_set_textarea(ui_context->ui->screen_1_ta_41, "passwd", root);
        lv_dropdown_set_selected(ui_context->ui->screen_1_ddlist_2, json_integer_value(json_object_get(root, "ptz_speed")) - 1);
    }
}

static void update_canvas_task(lv_timer_t *timer) {
    lv_ui_context *ui_context = (lv_ui_context *)timer->user_data;
    const char *image_data = ui_context->image_data;
    size_t image_size = ui_context->image_size;

    if (image_data && image_size > 0) {
//        lv_log("%llu\n", image_size);
//        lv_draw_img_dsc_t img_dst;
//        img_dst.opa = LV_OPA_100;
        lv_canvas_set_buffer(ui_context->ui->screen_1_canvas_1, (void *)ui_context->image_data, 640, 480, LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED);
//        lv_canvas_draw_img(ui_context->ui->screen_1_canvas_1, 0, 0, image_data, &img_dst);
        lv_img_set_src(ui_context->ui->screen_1_img_1, image_data);
    }
}

void receive_and_display_image(void *arg) {
    redisReply *reply;
    lv_ui_context *ui_context = (lv_ui_context *)arg;
    redisContext *redis_ctx = init_redis_context();
//    ui_context->image_data = lv_mem_alloc(640 * 480 * 4);
    if (NULL == redis_ctx) {
        lv_log("receive_and_display_image redis_ctx is null\n");
        return;
    }
    ui_context->image_data = lv_mem_alloc(640 * 480 * 4);
    subscribe_redis(redis_ctx, CAM_DATA_FETCH_CHANNEL);
    lv_log("receive_and_display_image thread begin");

//    lv_canvas_set_buffer(ui_context->ui->screen_1_canvas_1, (void *)ui_context->image_data, 640, 480, LV_IMG_CF_TRUE_COLOR);
    while (ui_context->image_run) {
        if (REDIS_OK == redisGetReply(redis_ctx, (void **)&reply)) {
            lv_log("%llu, type=%d, elements=%d\n", pthread_self(), reply->type, reply->elements);
            if ((reply->type == REDIS_REPLY_ARRAY) && (reply->elements == 3)) {
                const char *image_data = reply->element[2]->str;
                size_t image_size = reply->element[2]->len;
//                lv_log("image_size=%d\n", image_size);
//                memset(ui_context->image_data, 0, image_size);
                lv_memcpy(ui_context->image_data, image_data, image_size);
                // 将图像数据存储到上下文中
                ui_context->image_size = image_size;

                // 提交任务到主线程
                lv_timer_t *timer = lv_timer_create(update_canvas_task, 10, ui_context);
                lv_timer_set_repeat_count(timer, 1); // 只执行一次
            }
        }
    }
    lv_mem_free(ui_context->image_data);
    unsubscribe_redis(redis_ctx, CAM_DATA_FETCH_CHANNEL);
}

void show_cam_video_thread(lv_ui_context *ui_context, pthread_t *tid) {
    ui_context->image_run = 1;
    pthread_create(tid, NULL, (void *(*)(void *))receive_and_display_image, ui_context);
}