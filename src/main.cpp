#include "framebuffer.hpp"
#include "terminal.hpp"

#include <csignal>

volatile std::sig_atomic_t running = 1;

void handle_sigint(int sig) {
    (void)sig;
    running = 0;
}

int main() {
    std::signal(SIGINT, handle_sigint);

    auto [width, height] = Terminal::get_size();
    Framebuffer fbuff{width, height};

    Terminal::hide_cursor();
    
    fbuff.set_pixel(0, 0, '#');
    fbuff.set_pixel(15, 10, '#');
    fbuff.set_pixel(60, 20, '#');
    fbuff.set_pixel(35, 30, '#');
    fbuff.set_pixel(width-1, height-1, '#');

    while (running) {
        fbuff.print();
    }

    Terminal::show_cursor();

    return 0;
}
