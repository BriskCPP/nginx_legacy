//
// Created by ubuntu on 19-6-2.
//

#ifndef NGINX_COMMON_VALUE_UNSETVALUE_HPP
#define NGINX_COMMON_VALUE_UNSETVALUE_HPP

namespace toolset
{
    namespace nginx
    {
        namespace common
        {
            namespace value
            {
                class UnsetValue
                {
                private:
                    UnsetValue()
                    {
                    }

                    ~UnsetValue()
                    {
                    }

                public:
                    static const UnsetValue &constUnsetValue()
                    {
                        static const UnsetValue unsetValue;
                        return unsetValue;
                    }

                    static UnsetValue &unsetValue()
                    {
                        static UnsetValue unsetValue;
                        return unsetValue;
                    }

                    //下面是功能的具体实现
                    template<typename T>
                    operator T() const
                    {
                        return static_cast<T>(-1);
                    }

                    template<typename T>
                    operator T *() const
                    {
                        return reinterpret_cast<T *>(-1);
                    }

                    template<typename T, typename... Args>
                    static void unset(T &v, Args &...args)
                    {
                        v = unsetValue();
                        unset(args...);
                    }

                    template<typename T>
                    static void unset(T &v)
                    {
                        v = unsetValue();
                    }
                };
            }
        }
    }
}


#endif //NGINX_COMMON_VALUE_UNSETVALUE_HPP
