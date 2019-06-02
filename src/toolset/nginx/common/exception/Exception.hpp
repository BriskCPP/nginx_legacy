#include <utility>

#include <utility>

//
// Created by ubuntu on 19-6-2.
//

#ifndef NGINX_COMMON_EXCEPTION_EXCEPTION_HPP
#define NGINX_COMMON_EXCEPTION_EXCEPTION_HPP

#include <exception>
#include <string>

namespace toolset
{
    namespace nginx
    {
        namespace common
        {
            namespace exception
            {
                class Exception : public std::exception
                {
                private:
                    Exception() : code(-1)
                    {

                    }

                protected:

                    const int code;
                    const std::string message;

                public:
                    Exception(const int code, std::string message)
                            : code(code), message(std::move(message))
                    {
                        //好吧写到这里我就知道只能必须用C++了
                    }

                    const char *what() const noexcept override
                    {
                        return this->message.c_str();
                    }

                    virtual const int &getCode()
                    {
                        return code;
                    }
                };
            }
        }
    }
}


#endif //NGINX_COMMON_EXCEPTION_EXCEPTION_HPP
