#pragma once
#include <format>
#include <string>


namespace utils
{
    /**
     * @brief A wrapper for ::getenv().
     *
     * @param p_env The environment variable to get the value of.
     * @return A non empty string if the variable exist, else an empty string.
     */
    auto getenv( const std::string &p_env ) -> std::string_view;


    template<typename... T_Args>
    auto format( std::string_view p_fmt, T_Args &&...p_args ) -> std::string
    { return std::vformat(p_fmt, std::make_format_args(p_args...)); }
}