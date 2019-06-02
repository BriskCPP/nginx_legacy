//
// Created by ubuntu on 19-6-2.
//

#ifndef NGINX_COMMON_VALUE_VALUE_HPP
#define NGINX_COMMON_VALUE_VALUE_HPP

#include "UnsetValue.hpp"


namespace toolset
{
    namespace nginx
    {
        namespace common
        {
            namespace value
            {

                template<typename T>
                bool isUnset(const T &value)
                {
                    return value == static_cast<T>(UnsetValue::constUnsetValue());
                }

                template<typename ValueType, typename CandidateValueType>
                void setIfUnset(ValueType &value, const CandidateValueType &candidateValue)
                {
                    if (isUnset<ValueType>(value)) value = candidateValue;
                }
            }
        }
    }
}


#endif //NGINX_COMMON_VALUE_VALUE_HPP
