//
// Created by jon on 2025/3/16.
//

#include "events_cb.h"
#include "jansson.h"
#include "cam_setting.h"
#include "utils.h"
#include "pthread.h"

pthread_t cam_test_show_tid;

void subscribe_init(lv_ui_context *ui_context) {
    subscribe_redis(ui_context->c_sub, "tabview_1_query_cam_channel");
}

void screen_1_tabview_1_cb(lv_ui_context *ui_context) {
    int tab_index = lv_tabview_get_tab_act(ui_context->ui->screen_1_tabview_1);
    redisReply *reply;
    json_error_t error;
    json_t *root;
    switch (tab_index) {
        case 0:
            break;
        case 1:
            // 查询摄像机数据时候，索引给0表示获取全部数据
            root = json_object();
            json_object_set(root, "action", json_string("0"));
            json_object_set(root, "cam_no", json_string("0"));
            char *json_str = json_dumps(root, JSON_COMPACT);
            publish_msg_redis(ui_context->c_pub, CAM_DATA_CHANNEL, json_str);
            json_decref(root);
            if (REDIS_OK == redisGetReply(ui_context->c_sub, (void**)&reply)) {
                lv_log("type=%d, elements=%d\n", reply->type, reply->elements);
                const char *data = reply->element[2]->str;
                root = json_loads(data, 0, &error);
                if (!root) {
                    lv_log("error: on line %d: %s\n", error.line, error.text);
                } else {
                    lv_log(data);
                    fill_cam_setting(ui_context, root);
                }
            }
            break;
            case 2:
                publish_msg_redis(ui_context->c_pub, "tabview_2", "index2");
                break;
            default:
                break;
    }
}

// 选择摄像机编号，获取对应的数据
void screen_1_ddlist_1_cb(lv_ui_context *ui_context) {
    redisReply *reply;
    json_error_t error;
    json_t *root;
    uint16_t id = lv_dropdown_get_selected(ui_context->ui->screen_1_ddlist_1);
    lv_log("id=%d\n", id);
    char id_buf[8];
    snprintf(id_buf, 8, "%d", id + 1);
    root = json_object();
    json_object_set(root, "action", json_string(id_buf));
    json_object_set(root, "cam_no", json_string(id_buf));
    char *json_str = json_dumps(root, JSON_COMPACT);
    publish_msg_redis(ui_context->c_pub, CAM_DATA_CHANNEL, json_str);
    json_decref(root);
    if (REDIS_OK == redisGetReply(ui_context->c_sub, (void **) &reply)) {
        lv_log("type=%d, elements=%d\n", reply->type, reply->elements);
        const char *data = reply->element[2]->str;
        root = json_loads(data, 0, &error);
        if (!root) {
            lv_log("error: on line %d: %s\n", error.line, error.text);
        } else {
            fill_cam_setting(ui_context, root);
        }
    }
}

// 修改摄像机数据
void screen_1_btn_19_cb(lv_ui_context *ui_context) {
    const char *ip = lv_textarea_get_text(ui_context->ui->screen_1_ta_38);
    const char *port = lv_textarea_get_text(ui_context->ui->screen_1_ta_39);
    const char *username = lv_textarea_get_text(ui_context->ui->screen_1_ta_40);
    const char *passwd = lv_textarea_get_text(ui_context->ui->screen_1_ta_41);
    uint16_t ptz_speed = lv_dropdown_get_selected(ui_context->ui->screen_1_ddlist_2) + 1;
    uint16_t cam_no = lv_dropdown_get_selected(ui_context->ui->screen_1_ddlist_1) + 1;
    char p_cam_no[8];
    snprintf(p_cam_no, 8, "%d", cam_no);
    json_t *root = json_object();
    json_object_set(root, "ip", json_string(ip));
    json_object_set(root, "port", json_string(port));
    json_object_set(root, "username", json_string(username));
    json_object_set(root, "passwd", json_string(passwd));
    json_object_set(root, "ptz_speed", json_integer(ptz_speed));
    json_object_set(root, "action", json_string("-2"));
    json_object_set(root, "cam_no", json_string(p_cam_no));
    char *json_str = json_dumps(root, JSON_COMPACT);
    publish_msg_redis(ui_context->c_pub, CAM_DATA_CHANNEL, json_str);
    json_decref(root);
}

void screen_1_sw_1_cb(lv_ui_context *ui_context, int status) {
    lv_log("status=%d\n", status);
    uint16_t cam_no = lv_dropdown_get_selected(ui_context->ui->screen_1_ddlist_1) + 1;
    char p_cam_no[8];
    snprintf(p_cam_no, 8, "%d", cam_no);
    json_t *root = json_object();
    json_object_set(root, "cam_no", json_string(p_cam_no));

    if (status == 0) {
        ui_context->image_run = 0;
        json_object_set(root, "action", json_string("0"));
        char *json_str = json_dumps(root, JSON_COMPACT);
        publish_msg_redis(ui_context->c_pub, CAM_DATA_REQUEST_CHANNEL, json_str);
//        pthread_kill(cam_test_show_tid, 9);
//        lv_mem_free(ui_context->image_data);
//        pthread_join(cam_test_show_tid, NULL);
//        lv_log("cam thread stop");
    } else {
        json_object_set(root, "action", json_string("1"));
        char *json_str = json_dumps(root, JSON_COMPACT);
        publish_msg_redis(ui_context->c_pub, CAM_DATA_REQUEST_CHANNEL, json_str);
        show_cam_video_thread(ui_context, &cam_test_show_tid);
    }
    json_decref(root);
}

void screen_1_btn_21_cb(lv_ui_context *ui_context) {
    redisReply *reply;
    json_error_t error;
    json_t *root;
    size_t index;
    json_t *value;
    publish_msg_redis(ui_context->c_pub, CAM_WS_REQUEST_CHANNEL, "0");
    subscribe_redis(ui_context->c_sub, CAM_WS_INFO_CHANNEL);
    if (REDIS_OK == redisGetReply(ui_context->c_sub, (void **) &reply)) {
        const char *data = reply->element[2]->str;
        root = json_loads(data, 0, &error);
        if (json_is_array(root)) {
            json_array_foreach(root, index, value) {
                const char *ip = safe_get_json_string_value("ip", value);
                const char *port = safe_get_json_string_value("port", value);
                json_t *root_cam = json_object();
                char p_cam_no[8];
                snprintf(p_cam_no, 8, "%d", index+1);
                json_object_set(root_cam, "ip", json_string(ip));
                json_object_set(root_cam, "port", json_string(port));
                json_object_set(root_cam, "action", json_string("-2"));
                json_object_set(root_cam, "cam_no", json_string(p_cam_no));
                char *json_str = json_dumps(root_cam, JSON_COMPACT);
                publish_msg_redis(ui_context->c_pub, CAM_DATA_CHANNEL, json_str);
                uint16_t cam_no_index = lv_dropdown_get_selected(ui_context->ui->screen_1_ddlist_1);
                if (index == cam_no_index) {
                    safe_set_textarea(ui_context->ui->screen_1_ta_38, "ip", value);
                    safe_set_textarea(ui_context->ui->screen_1_ta_39, "port", value);
                }
                json_decref(root_cam);
            }
        } else {
            lv_log("cam_discovery_info not array\n");
        }
        json_decref(root);
    }
}
