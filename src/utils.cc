#include "utils.hh"


namespace utils
{
    auto
    getenv( const std::string &p_env ) -> std::string_view
    {
        const char *val { ::getenv(p_env.c_str()) };
        return val == nullptr ? "" : val;
    }
}