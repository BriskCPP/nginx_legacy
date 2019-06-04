cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(
        ./src/toolset/nginx/nginx_src/objs
        ./src/toolset/nginx/nginx_src/src/core
        ./src/toolset/nginx/nginx_src/src/event
        ./src/toolset/nginx/nginx_src/src/http
        ./src/toolset/nginx/nginx_src/src/http/modules
        ./src/toolset/nginx/nginx_src/src/http/v2
        ./src/toolset/nginx/nginx_src/src/os/unix
)

aux_source_directory(src/toolset/nginx/nginx_src/src/core NGXSRC_SRC_CORE)
aux_source_directory(src/toolset/nginx/nginx_src/src/event NGXSRC_SRC_EVENT)
aux_source_directory(src/toolset/nginx/nginx_src/src/event/modules NGXSRC_SRC_EVENT_MODULES)
list(FILTER NGXSRC_SRC_EVENT_MODULES EXCLUDE REGEX src/event/modules/ngx_kqueue_module.c$)
list(FILTER NGXSRC_SRC_EVENT_MODULES EXCLUDE REGEX src/event/modules/ngx_win32_poll_module.c$)
list(FILTER NGXSRC_SRC_EVENT_MODULES EXCLUDE REGEX src/event/modules/ngx_win32_select_module.c$)

aux_source_directory(src/toolset/nginx/nginx_src/src/http NGXSRC_SRC_HTTP)
aux_source_directory(src/toolset/nginx/nginx_src/src/http/modules NGXSRC_SRC_HTTP_MODULES)
aux_source_directory(src/toolset/nginx/nginx_src/src/http/v2 NGXSRC_SRC_HTTP_V2)
list(FILTER NGXSRC_SRC_HTTP_MODULES EXCLUDE REGEX modules/ngx_http_geoip_module.c$)
list(FILTER NGXSRC_SRC_HTTP_MODULES EXCLUDE REGEX modules/ngx_http_image_filter_module.c$)
list(FILTER NGXSRC_SRC_HTTP_MODULES EXCLUDE REGEX modules/ngx_http_stub_status_module.c$)
list(FILTER NGXSRC_SRC_HTTP_MODULES EXCLUDE REGEX modules/ngx_http_xslt_filter_module.c$)


#aux_source_directory(src/toolset/nginx/nginx_src/src/os/unix NGXSRC_SRC_OS_UNIX)
FILE(GLOB NGXSRC_SRC_OS_UNIX src/toolset/nginx/nginx_src/src/os/unix/*.c)

list(FILTER NGXSRC_SRC_OS_UNIX EXCLUDE REGEX darwin.*.c$)
list(FILTER NGXSRC_SRC_OS_UNIX EXCLUDE REGEX freebsd.*.c$)
list(FILTER NGXSRC_SRC_OS_UNIX EXCLUDE REGEX solaris.*.c$)

list(FILTER NGXSRC_SRC_OS_UNIX EXCLUDE REGEX /os/unix/ngx_file_aio_read.c$)
list(FILTER NGXSRC_SRC_OS_UNIX EXCLUDE REGEX /os/unix/ngx_linux_aio_read.c$)


aux_source_directory(src/toolset/nginx/nginx_src/objs NGXSRC_OBJS)


project(NginxModule_test)
project(NginxWorkbench_executable)
#这个可执行项目一定要最后再定义  因为CLion自动识别的项目名称是根目录下最后一个Project的名称

ADD_DEFINITIONS(-DNGINX_WORKBENCH) #这个宏定义是为了避免编译Nginx源代码中的main函数

add_library(NginxModule_test
            ${NGXSRC_SRC_CORE}
            ${NGXSRC_SRC_EVENT}
            ${NGXSRC_SRC_EVENT_MODULES}
            ${NGXSRC_SRC_HTTP}
            ${NGXSRC_SRC_HTTP_MODULES}
            ${NGXSRC_SRC_HTTP_V2}
            ${NGXSRC_SRC_OS_UNIX}
            ${NGXSRC_OBJS}
            src/toolset/nginx/module/ngx_test_module.cpp)

add_executable(NginxWorkbench_executable
               ${NGXSRC_SRC_CORE}
               ${NGXSRC_SRC_EVENT}
               ${NGXSRC_SRC_EVENT_MODULES}
               ${NGXSRC_SRC_HTTP}
               ${NGXSRC_SRC_HTTP_MODULES}
               ${NGXSRC_SRC_HTTP_V2}
               ${NGXSRC_SRC_OS_UNIX}
               ${NGXSRC_OBJS}
               main.cpp src/toolset/nginx/common/value/UnsetValue.hpp src/toolset/nginx/common/value/value.hpp src/toolset/nginx/common/exception/Exception.hpp src/toolset/nginx/common/exception/NgxException.hpp src/toolset/nginx/common/exception/NgxError.hpp src/toolset/nginx/nginx_src.h src/toolset/nginx/common/exception/NgxAgain.hpp src/toolset/nginx/common/exception/NgxBusy.hpp src/toolset/nginx/common/exception/NgxDone.hpp src/toolset/nginx/common/exception/NgxDeclined.hpp src/toolset/nginx/common/exception/NgxAbort.hpp src/toolset/nginx/common/exception/exception.h src/toolset/nginx/common/time/DateTime.hpp src/toolset/nginx/common/commons.h src/toolset/nginx/common/log/NginxLog.hpp)


TARGET_LINK_LIBRARIES(NginxWorkbench_executable NginxModule_test)


TARGET_LINK_LIBRARIES(NginxWorkbench_executable dl)
TARGET_LINK_LIBRARIES(NginxWorkbench_executable m)
TARGET_LINK_LIBRARIES(NginxWorkbench_executable pcre)
TARGET_LINK_LIBRARIES(NginxWorkbench_executable pthread)
TARGET_LINK_LIBRARIES(NginxWorkbench_executable crypt)
TARGET_LINK_LIBRARIES(NginxWorkbench_executable crypto)
TARGET_LINK_LIBRARIES(NginxWorkbench_executable ssl)
TARGET_LINK_LIBRARIES(NginxWorkbench_executable z)