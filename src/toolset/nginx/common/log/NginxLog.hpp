//
// Created by ubuntu on 19-6-4.
//

#ifndef NGINX_COMMON_LOG_NginxLog_HPP
#define NGINX_COMMON_LOG_NginxLog_HPP

#include "../../nginx_src.h"

namespace toolset
{
    namespace nginx
    {
        namespace common
        {
            namespace log
            {
                class NginxLog
                {
                private:
                    NginxLog() = default;

                public:
                    //工厂模式
                    static NginxLog get()
                    {
                        return NginxLog();
                    }

                    template<typename ... Args>
                    void stdError(ngx_log_t *log, const char *format, const Args &...args)
                    {
                        ngx_log_error_core(
                                NGX_LOG_STDERR, log,
                                static_cast<ngx_err_t>(NGX_LOG_STDERR),
                                format, args...
                        );
                    }

                    template<typename ... Args>
                    void emergent(ngx_log_t *log, const char *format, const Args &...args)
                    {
                        ngx_log_error_core(
                                NGX_LOG_EMERG, log,
                                static_cast<ngx_err_t>(NGX_LOG_EMERG),
                                format, args...
                        );
                    }

                    template<typename ... Args>
                    void alert(ngx_log_t *log, const char *format, const Args &...args)
                    {
                        ngx_log_error_core(
                                NGX_LOG_ALERT, log,
                                static_cast<ngx_err_t>(NGX_LOG_ALERT),
                                format, args...
                        );
                    }

                    template<typename ... Args>
                    void critical(ngx_log_t *log, const char *format, const Args &...args)
                    {
                        ngx_log_error_core(
                                NGX_LOG_CRIT, log,
                                static_cast<ngx_err_t>(NGX_LOG_CRIT),
                                format, args...
                        );
                    }

                    template<typename ... Args>
                    void error(ngx_log_t *log, const char *format, const Args &...args)
                    {
                        ngx_log_error_core(
                                NGX_LOG_ERR, log,
                                static_cast<ngx_err_t>(NGX_LOG_ERR),
                                format, args...
                        );
                    }

                    template<typename ... Args>
                    void warn(ngx_log_t *log, const char *format, const Args &...args)
                    {
                        ngx_log_error_core(
                                NGX_LOG_WARN, log,
                                static_cast<ngx_err_t>(NGX_LOG_WARN),
                                format, args...
                        );
                    }

                    template<typename ... Args>
                    void notice(ngx_log_t *log, const char *format, const Args &...args)
                    {
                        ngx_log_error_core(
                                NGX_LOG_NOTICE, log,
                                static_cast<ngx_err_t>(NGX_LOG_NOTICE),
                                format, args...
                        );
                    }

                    template<typename ... Args>
                    void info(ngx_log_t *log, const char *format, const Args &...args)
                    {
                        ngx_log_error_core(
                                NGX_LOG_INFO, log,
                                static_cast<ngx_err_t>(NGX_LOG_INFO),
                                format, args...
                        );
                    }

                    template<typename ... Args>
                    void debug(ngx_log_t *log, const char *format, const Args &...args)
                    {
                        ngx_log_error_core(
                                NGX_LOG_DEBUG, log,
                                static_cast<ngx_err_t>(NGX_LOG_DEBUG),
                                format, args...
                        );
                    }
                };
            }
        }
    }
}
#endif //NGINX_COMMON_LOG_NginxLog_HPP
