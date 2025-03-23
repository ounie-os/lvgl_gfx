//
// Created by jon on 2025/3/18.
//

#include "utils.h"

void safe_set_textarea(lv_obj_t* textarea, const char* json_key, json_t* value) {
    if (textarea == NULL) {
        // 记录日志或采取其他措施
        fprintf(stderr, "Textarea is NULL for key: %s\n", json_key);
        return;
    }

    json_t* field = json_object_get(value, json_key);
    if (field == NULL || !json_is_string(field)) {
        // 如果字段不存在或不是字符串类型，设置为空字符串
        lv_textarea_set_text(textarea, "");
        fprintf(stderr, "Invalid or missing JSON field: %s\n", json_key);
        return;
    }

    const char* text = json_string_value(field);
    if (text == NULL) {
        // 如果字符串值为空，设置为空字符串
        lv_textarea_set_text(textarea, "");
        fprintf(stderr, "Null string value for JSON field: %s\n", json_key);
        return;
    }

    lv_textarea_set_text(textarea, text);
}

const char* safe_get_json_string_value(const char* json_key, json_t* value) {
    json_t* field = json_object_get(value, json_key);
    if (field == NULL || !json_is_string(field)) {
        // 如果字段不存在或不是字符串类型，设置为空字符串
        fprintf(stderr, "Invalid or missing JSON field: %s\n", json_key);
        return NULL;
    }

    const char* text = json_string_value(field);
    if (text == NULL) {
        // 如果字符串值为空，设置为空字符串
        fprintf(stderr, "Null string value for JSON field: %s\n", json_key);
        return NULL;
    }
    return text;
}
