//
// Created by jon on 2025/3/13.
//

#include "redis_lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

// 初始化 Redis 连接
redisContext* init_redis(const char* ip, int port) {
    struct timeval timeout = { 1, 500000 }; // 1.5秒超时

    redisContext *c = redisConnectWithTimeout(ip, port, timeout);
    if (c == NULL || c->err) {
        if (c) {
            printf("Redis conn error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("no Redis connection\n");
        }
        return NULL;
    }
    printf("Redis ok\n");
    return c;
}

int auth_redis(redisContext* c, const char* password) {
    redisReply *reply = redisCommand(c, "AUTH %s", password);
    if (reply->type == REDIS_REPLY_STATUS && strcmp(reply->str, "OK") == 0) {
        printf("密码验证成功\n");
        return 0;
    } else {
        printf("密码验证失败: %s\n", reply->str);
        freeReplyObject(reply);
        redisFree(c);
        return 1;
    }
}

int publish_msg_redis(redisContext *c, const char *channel, const char *message) {
    redisReply *reply = redisCommand(c, "PUBLISH %s %s", channel, message);
    if (reply->type == REDIS_REPLY_INTEGER) {
        printf("msg pub ok, subscribe num: %lld\n", reply->integer);
        return 0;
    } else {
        printf("msg pub fail: %s\n", reply->str);
        return 1;
    }
}

int subscribe_redis(redisContext *c, const char *channel) {
    int ret = 0;
    redisReply *reply = redisCommand(c, "SUBSCRIBE %s", channel);
    if (reply->type == REDIS_REPLY_ARRAY) {
        printf("sub ok, wait msg...\n");
        ret = 0;
    } else {
        printf("sub fail: %s\n", reply->str);
        ret = 1;
    }
    freeReplyObject(reply);
    return ret;
}

int unsubscribe_redis(redisContext *c, const char *channel) {
    int ret = 0;
    redisReply *reply = redisCommand(c, "UNSUBSCRIBE %s", channel);
    if (reply->type == REDIS_REPLY_ARRAY) {
        printf("unsubscribe %s ok\n", channel);
        ret = 0;
    } else {
        printf("unsubscribe %s fail: %s\n", channel, reply->str);
        ret = 1;
    }
    freeReplyObject(reply);
    return ret;
}
