#include <iostream>
#include <print>

#include <csignal>

#include "shell/parser.hh"


auto
main( int32_t p_argc, char **p_argv ) -> int32_t
{
    std::signal(SIGINT, shell::sigint_handler);

    std::string buffer;

    while (true) {
        std::print("% $ ");

        int32_t retval { shell::input_event(buffer) };
        if (retval == EINTR) continue;
        if (retval == EOF) {
            std::println("\n{}: Exiting from EOF.", APP_NAME);
            break;
        }

        std::vector<std::string> tokens { shell::parse_input(buffer) };

        for (std::string &token : tokens)
            std::println("{}", token);
        buffer.clear();
    }
}