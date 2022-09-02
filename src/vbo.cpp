#include "vbo.hpp"
#include <iostream>

#include <GL/glew.h>

VBO::VBO(vertex vertices[], unsigned int length)
{
    glGenBuffers(1, &ID);
    use();
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * length, vertices, GL_STATIC_DRAW);
    std::cout << "init" << std::endl;
}

void VBO::use()
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}
