//
// Created by ubuntu on 19-6-2.
//

#ifndef NGINX_COMMON_EXCEPTION_NgxEXCEPTION_HPP
#define NGINX_COMMON_EXCEPTION_NgxEXCEPTION_HPP

#include "Exception.hpp"
#include <string>
#include <memory>

#include "../../nginx_src.h"

namespace toolset
{
    namespace nginx
    {
        namespace common
        {
            namespace exception
            {


                //NgxException的声明
                class NgxException : public Exception
                {

                public:
                    inline explicit NgxException(ngx_int_t errorCode) :
                            Exception(
                                    static_cast<int>(errorCode),
                                    std::string("Nginx Error:") + std::to_string(errorCode)
                            )
                    {
                    }

                    inline const NgxException &explicitType() const noexcept;

                    template<class ExplicitType>
                    inline bool isType() const noexcept
                    {
                        try
                        {
                            dynamic_cast<const ExplicitType &>(this->explicitType());
                            return true;
                        }
                        catch (std::bad_cast &)
                        {
                            return false;
                        }
                    }

                };

                class NgxOkWithoutError : public NgxException
                {
                    friend class NgxException;

                private:
                    NgxOkWithoutError() : NgxException(NGX_OK)
                    {
                    }
                };

                class NgxAbort : public NgxException
                {
                    friend class NgxException;

                private:
                    NgxAbort() : NgxException(NGX_ABORT)
                    {
                    }
                };

                class NgxAgain : public NgxException
                {
                    friend class NgxException;

                private:
                    NgxAgain() : NgxException(NGX_AGAIN)
                    {
                    }
                };

                class NgxBusy : public NgxException
                {
                    friend class NgxException;

                private:
                    NgxBusy() : NgxException(NGX_BUSY)
                    {
                    }
                };

                class NgxDeclined : public NgxException
                {
                    friend class NgxException;

                private:
                    NgxDeclined() : NgxException(NGX_DECLINED)
                    {
                    }
                };

                class NgxDone : public NgxException
                {
                    friend class NgxException;

                private:
                    NgxDone() : NgxException(NGX_DONE)
                    {
                    }
                };

                class NgxError : public NgxException
                {
                    friend class NgxException;

                private:
                    NgxError() : NgxException(NGX_ERROR)
                    {
                    }
                };


                const NgxException &NgxException::explicitType() const noexcept
                {
                    switch (this->code)
                    {
                        case NGX_OK:
                            static const NgxOkWithoutError ngxOkWithoutError;
                            return ngxOkWithoutError;
                        case NGX_ABORT:
                            static const NgxAbort ngxAbort;
                            return ngxAbort;
                        case NGX_AGAIN:
                            static const NgxAgain ngxAgain;
                            return ngxAgain;
                        case NGX_BUSY:
                            static const NgxBusy ngxBusy;
                            return ngxBusy;
                        case NGX_DECLINED:
                            static const NgxDeclined ngxDeclined;
                            return ngxDeclined;
                        case NGX_DONE:
                            static const NgxDone ngxDone;
                            return ngxDone;
                        case NGX_ERROR:
                            static const NgxError ngxError;
                            return ngxError;
                        default:
                            return *this;
                    }
                }
            };
        }
    }
}

#endif //NGINX_COMMON_EXCEPTION_NgxEXCEPTION_HPP
