//
// Created by ubuntu on 19-6-4.
//

#ifndef NGINX_MODULE_NGX_TEST_MODULE_HPP
#define NGINX_MODULE_NGX_TEST_MODULE_HPP

#include <cassert>
#include "../nginx_src.h"


#include "../common/value/UnsetValue.hpp"
#include "../common/exception/NgxException.hpp"

#include "../common/log/NginxLog.hpp"

using toolset::nginx::common::log::NginxLog;


struct ModuleConfig final
{
    ngx_flag_t enabled = NGX_CONF_UNSET;//toolset::nginx::common::value::UnsetValue::unsetValue();
};


//静态变量  全局只有一份
static ngx_command_t moduleCommands[] =
        {
                {
                        ngx_string("test_switch"),//在配置文件中指令的名称
                        NGX_HTTP_LOC_CONF | NGX_CONF_FLAG,//指令的作用域和类型
                        ngx_conf_set_flag_slot,//解析用的函数指针
                        NGX_HTTP_LOC_CONF_OFFSET,//数据的存储位置类型
                        offsetof(ModuleConfig, enabled), //具体的偏移量
                        nullptr//暂时不用关心
                },
                ngx_null_command//用一个空对象结束数组
        };


static ngx_int_t handler(ngx_http_request_t *r);//声明在前



static ngx_int_t init(ngx_conf_t *config)
{
    auto httpCoreMainConfig = reinterpret_cast<ngx_http_core_main_conf_t *>(
            ngx_http_conf_get_module_main_conf(config, ngx_http_core_module)
    );


//    auto temp = reinterpret_cast<ngx_http_handler_pt *>(
//            ngx_array_push(&(httpCoreMainConfig->phases[NGX_HTTP_REWRITE_PHASE].handlers))
//    );
//    *temp = handler;
    *reinterpret_cast<ngx_http_handler_pt *>(
            ngx_array_push(&(httpCoreMainConfig->phases[NGX_HTTP_REWRITE_PHASE].handlers))
    ) = handler;

    return NGX_OK;
}

void *create(ngx_conf_t *config)
{
    auto p = ngx_pcalloc(config->pool, sizeof(ModuleConfig));

    if (!p)
    {
        using toolset::nginx::common::exception::NgxException;
        throw NgxException(-10);
    }

    assert(p);
    return p;
}

char *merge(ngx_conf_t *, void *prev, void *conf)
{
    if (reinterpret_cast<ModuleConfig *>(prev)->enabled == NGX_CONF_UNSET)
    {
        reinterpret_cast<ModuleConfig *>(conf)->enabled = 1;
    }
    else
    {
        reinterpret_cast<ModuleConfig *>(conf)->enabled =
                reinterpret_cast<ModuleConfig *>(prev)->enabled;
    }
    return NGX_CONF_OK;
}


static ngx_http_module_t ngxHttpModule =
        {
                nullptr,    /**pre-configuration 解析配置文件前被调用*/
                init,       /**post-configuration 解析配置文件后被调用*/
                nullptr,    /**create_main_conf 创建http main域的配置结构*/
                nullptr,    /**init_main_conf 初始化http main域的配置结构*/
                nullptr,    /**create_srv_conf 创建server域的配置结构*/
                nullptr,    /**merge_srv_conf 合并server域的配置结构*/
                create,     /**create_loc_conf 创建location域的配置结构*/
                merge       /**merge_loc_conf 合并location域的配置结构*/
        };

ngx_module_t ngxTestModule =
        {
                NGX_MODULE_V1,
                &ngxHttpModule,
                moduleCommands,
                NGX_HTTP_MODULE, //表明该模块是HTTP模块的TAG
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                NGX_MODULE_V1_PADDING//标准填充宏
        };


#include <iostream>

static ngx_int_t handler(ngx_http_request_t *r)
{
    auto moduleConfig = reinterpret_cast<ModuleConfig *>(
            ngx_http_get_module_loc_conf(r, ngxTestModule)
    );

    NginxLog::get().notice(r->connection->log, "Hello Nginx Module");
    //运行日志

    if (moduleConfig->enabled)
    {
        std::cout << "module enabled" << std::endl;
    }
    else
    {
        std::cout << "module disabled" << std::endl;
    }

    return NGX_DECLINED;
    //因为我们没有真正地处理数据，所以我们要用DECLINED，这样NGINX才会继续调用后面的模块进行处理
}

#endif //NGINX_MODULE_NGX_TEST_MODULE_HPP
