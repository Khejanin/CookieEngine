#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/Singleton.hpp"

class Window
{
public:
    Window();
    virtual ~Window();

    bool ShouldClose();
    void DoFrame();

private:
    static void WindowResizeCallback(GLFWwindow* window, int width, int height);

private:
    GLFWwindow* m_Window;
};
