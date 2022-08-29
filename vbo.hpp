#pragma once
#include "vertex.hpp"

class VBO
{
    public:
        unsigned int ID;
        vertex data[];

        void use();

        VBO(vertex vertices[], unsigned int length);
};
