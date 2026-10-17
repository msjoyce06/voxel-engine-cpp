#include "terminal.hpp"

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdexcept>
#include <iostream>

Terminal::Size Terminal::get_size() {
    winsize size{};

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) == -1 ||
        size.ws_col == 0 || size.ws_row == 0) {
        throw std::runtime_error("Failed to get terminal size");
    }

    return {
        static_cast<int>(size.ws_col),
        static_cast<int>(size.ws_row)
    };
}

void Terminal::hide_cursor() {
    std::cout << "\x1b[?25l";
}

void Terminal::show_cursor() {
    std::cout << "\x1b[?25h" << std::flush;
}

void Terminal::top_left() {
    std::cout << "\x1b[H";
}
