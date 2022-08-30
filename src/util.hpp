#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace util
{
    // reduce boilerplate in main file
    GLFWwindow* setup();
    void terminate();
}
