#include <print>
#include "exception.hh"


void
exception::print_msg( const std::string &p_func,
                      const std::string &p_file,
                      const int32_t      p_line ) const
{
    std::string func { p_func.substr(p_func.find_first_of(' ') + 1) };
    func = func.substr(0, func.find('('));

    std::println("An exception occured in {}() at {}:{}", func, p_file, p_line);
    std::println("  what(): {}", m_msg);
}


void
stream_error::print_msg( const std::string &p_func,
                         const std::string &p_file,
                         const int32_t      p_line ) const
{
    std::string func { p_func.substr(p_func.find_first_of(' ') + 1) };
    func = func.substr(0, func.find('('));

    std::println("A stream_error occured in {}() at {}:{}",
                  func, p_file, p_line);
    std::println("  what(): {}", m_msg);
}