#include <string>
#include <stdexcept>
#include "Window.hpp"

Window::Window()
{
    //Init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Create GLFW Window
    m_Window = glfwCreateWindow(800, 600, "Cookies!", NULL, NULL);
    if (m_Window == NULL)
    {
        glfwTerminate();
        throw new std::runtime_error(std::string("Failed to Create GLFW window"));
    }
    glfwMakeContextCurrent(m_Window);

    //Load GLAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        throw new std::runtime_error(std::string("Failed to initialize GLAD"));
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(m_Window, WindowResizeCallback);
}

void Window::WindowResizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(m_Window);
}

void Window::DoFrame()
{
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

Window::~Window()
{
}
