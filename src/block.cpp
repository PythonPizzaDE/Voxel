#include <iostream>

#include "block.hpp"
#include "vertex.hpp"

vertex vertices[] = {
    vertex { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f },
    vertex {  0.5f, -0.5f, -0.5f,  1.0f, 0.0f },
    vertex {  0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
    vertex {  0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
    vertex { -0.5f,  0.5f, -0.5f,  0.0f, 1.0f },
    vertex { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f },

    vertex { -0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
    vertex {  0.5f, -0.5f,  0.5f,  1.0f, 0.0f },
    vertex {  0.5f,  0.5f,  0.5f,  1.0f, 1.0f },
    vertex {  0.5f,  0.5f,  0.5f,  1.0f, 1.0f },
    vertex { -0.5f,  0.5f,  0.5f,  0.0f, 1.0f },
    vertex { -0.5f, -0.5f,  0.5f,  0.0f, 0.0f },

    vertex { -0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
    vertex { -0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
    vertex { -0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
    vertex { -0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
    vertex { -0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
    vertex { -0.5f,  0.5f,  0.5f,  1.0f, 0.0f },

    vertex {  0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
    vertex {  0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
    vertex {  0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
    vertex {  0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
    vertex {  0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
    vertex {  0.5f,  0.5f,  0.5f,  1.0f, 0.0f },

    vertex { -0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
    vertex {  0.5f, -0.5f, -0.5f,  1.0f, 1.0f },
    vertex {  0.5f, -0.5f,  0.5f,  1.0f, 0.0f },
    vertex {  0.5f, -0.5f,  0.5f,  1.0f, 0.0f },
    vertex { -0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
    vertex { -0.5f, -0.5f, -0.5f,  0.0f, 1.0f },

    vertex { -0.5f,  0.5f, -0.5f,  0.0f, 1.0f },
    vertex {  0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
    vertex {  0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
    vertex {  0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
    vertex { -0.5f,  0.5f,  0.5f,  0.0f, 0.0f },
    vertex { -0.5f,  0.5f, -0.5f,  0.0f, 1.0f }
};

Block::Block(unsigned int shader) : vbo(vertices, 36)
{
    modelMatrixLocation = glGetUniformLocation(shader, "model");
}

void Block::render(glm::vec3 position)
{
    vbo.use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);

    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(model));
    std::cout << "draw it" << std::endl;
    glDrawArrays(GL_TRIANGLES, 0, 36);
    std::cout << "finished drawing" << std::endl;
}
