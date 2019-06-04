//
// Created by ubuntu on 19-6-2.
//

#ifndef TOOLSET_NGINX_NGINX_SRC_H
#define TOOLSET_NGINX_NGINX_SRC_H


extern "C"
{

#include <openssl/opensslv.h>
#include <openssl/crypto.h>
#include <openssl/bio.h>
#include <openssl/x509.h>
#include <openssl/ocsp.h>

#include <poll.h>

#include "./nginx_src/src/http/ngx_http.h"

#include "./nginx_src/src/core/nginx.h"//含有版本号
#include "./nginx_src/src/core/ngx_config.h"//含有整数相关定义
#include "./nginx_src/src/core/ngx_core.h"//含有错误类型码
#include "./nginx_src/src/core/ngx_cycle.h"
#include "./nginx_src/src/core/ngx_module.h"
#include "./nginx_src/src/core/ngx_palloc.h"
#include "./nginx_src/src/core/ngx_times.h"//含有时间相关的
#include "./nginx_src/src/os/unix/ngx_time.h"
#include "./nginx_src/src/core/ngx_parse_time.h"
#include "./nginx_src/src/core/ngx_log.h"


};

#endif //TOOLSET_NGINX_NGINX_SRC_H
