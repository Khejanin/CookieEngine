#include <iostream>
#include "core/Engine.hpp"
#include "graphics/Window.hpp"

int main() {
    Window window;

    while(!window.ShouldClose())
    {
        window.DoFrame();
    }

    return 0;
}
