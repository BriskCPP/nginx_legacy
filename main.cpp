#include <iostream>

#include "src/toolset/nginx/common/value/value.hpp"
#include "src/toolset/nginx/common/exception/exception.h"

#include <typeinfo>

#include <cstdio>

using toolset::nginx::common::value::UnsetValue;
using toolset::nginx::common::exception::NgxException;

int main()
{


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