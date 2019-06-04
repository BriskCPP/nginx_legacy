//
// Created by ubuntu on 19-6-3.
//

#ifndef NGINX_COMMON_TIME_DATETIME_HPP
#define NGINX_COMMON_TIME_DATETIME_HPP

#include "../../nginx_src.h"

namespace toolset
{
    namespace nginx
    {
        namespace common
        {
            namespace time
            {
                class DateTime final
                {
                private:
                    ngx_time_t ngxTime;

                    //DateTime() = default;

                    explicit DateTime(
                            const ngx_time_t &ngxTime = {
                                    ngx_cached_time->sec,
                                    ngx_cached_time->msec,
                                    ngx_cached_time->gmtoff
                            }
                    ) : ngxTime{ngxTime.sec, ngxTime.msec, ngxTime.gmtoff}
                    {
                    }

                public:
                    enum Zone
                    {
                        Local,
                        GMT
                    };

                    static const DateTime get(bool updateNow = false)
                    {
                        if (updateNow) ngx_time_update();
                        return DateTime();
                    }


                    //下面是具体的函数
                    const int millisecond() const
                    {
                        return static_cast<int>(ngxTime.msec);
                    }

                    const int seconds(Zone zone = Local) const
                    {
                        ngx_tm_t temp;
                        switch (zone)
                        {

                            case GMT:
                                ngx_gmtime(this->ngxTime.sec, &temp);
                                return temp.tm_sec;
                            case Local:
                            default:
                                ngx_localtime(this->ngxTime.sec, &temp);
                                return temp.tm_sec;
                        }
                    }

                    const int minutes(Zone zone = Local) const
                    {
                        ngx_tm_t temp;
                        switch (zone)
                        {

                            case GMT:
                                ngx_gmtime(this->ngxTime.sec, &temp);
                                return temp.tm_min;
                            case Local:
                            default:
                                ngx_localtime(this->ngxTime.sec, &temp);
                                return temp.tm_min;
                        }
                    }

                    const int hours(Zone zone = Local) const
                    {
                        ngx_tm_t temp;
                        switch (zone)
                        {

                            case GMT:
                                ngx_gmtime(this->ngxTime.sec, &temp);
                                return temp.tm_hour;
                            case Local:
                            default:
                                ngx_localtime(this->ngxTime.sec, &temp);
                                return temp.tm_hour;
                        }
                    }
                };
            }
        }
    }
}

#endif //NGINX_COMMON_TIME_DATETIME_HPP
