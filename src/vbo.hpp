#pragma once
#include "vertex.hpp"
#include "usable.hpp"

class VBO : public Usable
{
    public:
        unsigned int ID;
        vertex data[];

        void use();

        VBO(vertex vertices[], unsigned int length);
};
