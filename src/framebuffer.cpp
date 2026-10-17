#include "framebuffer.hpp"
#include "terminal.hpp"

#include <iostream>
#include <string>

Framebuffer::Framebuffer(int width, int height)
    : _width(width),
      _height(height),
      _pixels(width * height, ' ') {}

void Framebuffer::set_pixel(int x, int y, char c) {
    if (x < 0 || x >= _width || y < 0 || y > _height)
        return;

    _pixels[y * _width + x] = c;
}

void Framebuffer::print() const {
    Terminal::top_left();
    std::string output;

    for (int y = 0; y < _height; y++) {
        output.append(_pixels, y * _width, _width);

        if (y != _height - 1)
            output += '\n';
    }

    std::cout << output << std::flush;
}
