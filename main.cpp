#include <iostream>

#include "src/toolset/nginx/common/commons.h"

#include <typeinfo>

#include <cstdio>

using toolset::nginx::common::time::DateTime;
using toolset::nginx::common::value::UnsetValue;
using toolset::nginx::common::exception::NgxException;

int main()
{

    DateTime dateTime = DateTime::get();
    std::cout << dateTime.hours() << ":" << dateTime.minutes() << ":" << dateTime.seconds() << "." << dateTime.millisecond() << std::endl;


    const NgxException ngxException = NgxException(-2);
    //const NgxException &a = ngxException.explicitType();
    //dynamic_cast<const toolset::nginx::common::exception::NgxAbort &>(a);
    std::cout << ngxException.isType<toolset::nginx::common::exception::NgxAgain>() << std::endl;
    //std::cout << typeid(a).name() << std::endl;
    //UnsetValue &unsetValue1 = UnsetValue::unsetValue();
    //UnsetValue &unsetValue2 = UnsetValue::unsetValue();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}