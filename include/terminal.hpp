#pragma once

#include <string>

class Terminal {
public:
    struct Size {
        int width;
        int height;
    };

    static Size get_size();

    static void hide_cursor();
    static void show_cursor();
    static void top_left();
};
