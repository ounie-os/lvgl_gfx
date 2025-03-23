//
// Created by jon on 2025/3/13.
//

#ifndef LVGL_REDIS_LIB_H
#define LVGL_REDIS_LIB_H

#include "hiredis.h"

redisContext* init_redis(const char* ip, int port);
int auth_redis(redisContext* c, const char* password);
int publish_msg_redis(redisContext *c, const char *channel, const char *message);
int subscribe_redis(redisContext *c, const char *channel);
int unsubscribe_redis(redisContext *c, const char *channel);

#endif //LVGL_REDIS_LIB_H
