#include <iostream>

// use (modern) OpenGL
#define GLEW_STATIC
#include <GL/glew.h>

// windowing and input
#include <GLFW/glfw3.h>

// utilities for creating windows etc.
#include "util.hpp"
#include "shader_s.hpp"
#include "block.hpp"

// image loading #define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

// math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>
#include <math.h>

#include "vbo.hpp"
#include "camera.hpp"

/* vertex vertices[] = { */
/*     vertex { -0.5f, -0.5f, 0.0f, 0.0f, 0.0f }, */
/*     vertex {  0.5f, -0.5f, 0.0f, 1.0f, 0.0f }, */
/*     vertex {  0.0f,  0.5f, 0.0f, 0.5f, 1.0f }, */
/* }; */

double mouseXPos;
double mouseYPos;

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    mouseXPos = xpos;
    mouseYPos = ypos;
}

int main(int argc, char** argv)
{
    GLFWwindow* window = util::setup();

    glfwSetCursorPosCallback(window, mouse_callback);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    Shader shader ("shaders/vertex.glsl", "shaders/fragment.glsl");
    shader.use();

    /* VBO vbo (vertices, 3); */
    /* vbo.use(); */
    Block block (shader.ID);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // glm::vec3 position, float pitch, float yaw, glm::vec3 up, float speed, float mouse_sensitivity, float fov, GLFWwindow* window, unsigned int shader
    Camera cam (glm::vec3(0.0f, 0.0f, 3.0f), 0.0f, -90.0f, glm::vec3(0.0f, 1.0f, 0.0f), 5.0f, 0.01f, 45.0f, window, shader.ID);

    float currentFrame = glfwGetTime();
    float lastFrame = 0.0f;

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window))
    {
        currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        cam.processInput(window, deltaTime);
        cam.mouse_callback(mouseXPos, mouseYPos);
        cam.Update();


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* std::cout << 1.0f / deltaTime << std::endl; */

        for (float x = 0; x < 10; x++)
        {
            for (float y = 0; y < 10; y++)
            {
                for (float z = 0; z < 10; z++)
                {
                    block.render(glm::vec3(x, y, z));
                }
            }
        }

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
    }

    util::terminate();
}
