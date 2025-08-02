#pragma once
#include <string_view>
#include <format>

#define PRINT_MSG() \
    print_msg( __PRETTY_FUNCTION__, __FILE__, __LINE__ )


template<class T_Exception, typename... T_Args>
[[noreturn]]
void fthrow( std::string_view p_fmt, T_Args &&...p_args )
{
    T_Exception except { p_fmt, std::forward<T_Args>(p_args)... };
    except.PRINT_MSG();
    std::abort();
}


class exception
{
public:
    template<typename... T_Args>
    exception( std::string_view p_fmt, T_Args &&...p_args ) :
        m_msg(std::vformat(p_fmt, std::make_format_args(p_args...)))
    {}

    virtual ~exception() = default;


    virtual void print_msg( const std::string &p_func,
                            const std::string &p_file,
                            const int32_t      p_line ) const;


protected:
    std::string m_msg;
};


class stream_error : public exception
{
public:
    using exception::exception;

    void print_msg( const std::string &p_func,
                    const std::string &p_file,
                    const int32_t      p_line ) const override;

protected:
    using exception::m_msg;
};