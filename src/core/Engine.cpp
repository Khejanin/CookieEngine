#include "Engine.hpp"
#include <iostream>

namespace Core
{
    Engine::Engine():
            is_running(true)
    {
    }

    void Engine::Run()
    {
        while(is_running)
        {
            std::cout << "Engine is running";
            return;
        }
    }
}