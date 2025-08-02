#pragma once
#include <string>
#include <vector>


namespace shell
{
    void sigint_handler( int32_t );
    auto input_event( std::string &p_buffer ) -> int32_t;


    [[nodiscard]]
    auto parse_input( const std::string &p_input ) -> std::vector<std::string>;
}