#pragma once

#include "vbo.hpp"
#include "shader_s.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>

#include <GL/glew.h>

class Block
{
    public:
        Block(unsigned int shader);

        void render(glm::vec3 position);

    private:
        unsigned int modelMatrixLocation;
        VBO vbo;
};
