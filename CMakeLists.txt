cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(
        ./src/toolset/nginx/nginx_src/objs
        ./src/toolset/nginx/nginx_src/src/core
        ./src/toolset/nginx/nginx_src/src/event
        ./src/toolset/nginx/nginx_src/src/os/unix
)


project(NginxUtils_executable)
project(NginxUtils_staticLib)

add_executable(NginxUtils_executable main.cpp src/toolset/nginx/common/value/UnsetValue.hpp src/toolset/nginx/common/value/value.hpp src/toolset/nginx/common/exception/Exception.hpp src/toolset/nginx/common/exception/NgxException.hpp src/toolset/nginx/common/exception/NgxError.hpp src/toolset/nginx/nginx_src.h src/toolset/nginx/common/exception/NgxAgain.hpp src/toolset/nginx/common/exception/NgxBusy.hpp src/toolset/nginx/common/exception/NgxDone.hpp src/toolset/nginx/common/exception/NgxDeclined.hpp src/toolset/nginx/common/exception/NgxAbort.hpp src/toolset/nginx/common/exception/exception.h)
add_library(NginxUtils_staticLib main.cpp src/toolset/nginx/common/value/UnsetValue.hpp src/toolset/nginx/common/value/value.hpp src/toolset/nginx/common/exception/Exception.hpp src/toolset/nginx/common/exception/NgxException.hpp src/toolset/nginx/common/exception/NgxError.hpp src/toolset/nginx/nginx_src.h src/toolset/nginx/common/exception/NgxAgain.hpp src/toolset/nginx/common/exception/NgxBusy.hpp src/toolset/nginx/common/exception/NgxDone.hpp src/toolset/nginx/common/exception/NgxDeclined.hpp src/toolset/nginx/common/exception/NgxAbort.hpp src/toolset/nginx/common/exception/exception.h)