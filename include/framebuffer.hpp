#pragma once

#include <string>

class Framebuffer {
public:
    Framebuffer(int width, int height);

    void set_pixel(int x, int y, char c);
    void print() const;

private:
    int _width, _height;
    std::string _pixels;
};
