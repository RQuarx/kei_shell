#include <iostream>
#include <sstream>
#include <atomic>

#include <cstring>

#include "shell/parser.hh"
#include "exception.hh"


namespace shell
{
    std::atomic<bool> sigint_req { false };


    void
    sigint_handler( int32_t )
    {
        sigint_req = true;
        std::cout << std::endl;
    }


    auto
    input_event( std::string &p_buffer ) -> int32_t
    {
        if (!std::getline(std::cin, p_buffer)) {
            if (std::cin.eof()) return EOF;

            if (errno == EINTR) {
                sigint_req = false;
                std::cin.clear();
                return EINTR;
            }

            fthrow<stream_error>("std::getline failed: {}",
                                 std::strerror(errno));
        }

        return 0;
    }


    auto
    parse_input( const std::string &p_input ) -> std::vector<std::string>
    {
        std::vector<std::string> tokens;

        std::istringstream iss { p_input };
        std::string token;

        while (std::getline(iss, token, ' ')) tokens.emplace_back(token);

        return tokens;
    }
}