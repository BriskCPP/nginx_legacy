//
// Created by ubuntu on 19-6-2.
//

#ifndef TOOLSET_NGINX_NGINX_SRC_H
#define TOOLSET_NGINX_NGINX_SRC_H


extern "C"
{
#include "./nginx_src/src/core/nginx.h"//含有版本号
#include "./nginx_src/src/core/ngx_config.h"//含有整数相关定义
#include "./nginx_src/src/core/ngx_core.h"//含有错误类型码
};

#endif //TOOLSET_NGINX_NGINX_SRC_H
