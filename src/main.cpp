#include <iostream>

// use (modern) OpenGL
#define GLEW_STATIC
#include <GL/glew.h>

// windowing and input
#include <GLFW/glfw3.h>

// utilities for creating windows etc.
#include "util.hpp"
#include "shader_s.hpp"

// image loading
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

// math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>
#include <math.h>

#include "vbo.hpp"
#include "camera.hpp"

vertex vertices[] = {
    vertex { -0.5f, -0.5f, 0.0f, 0.0f, 0.0f },
    vertex {  0.5f, -0.5f, 0.0f, 1.0f, 0.0f },
    vertex {  0.0f,  0.5f, 0.0f, 0.5f, 1.0f },
};

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

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    VBO vbo (vertices, 3);
    vbo.use();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    Shader shader ("shaders/vertex.glsl", "shaders/fragment.glsl");
    shader.use();

    // (glm::vec3 position, glm::vec3 front, glm::vec3 up, float speed, float mouse_sensitivity, float fov, GLFWwindow* window, unsigned int shader)
    Camera cam (glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), 5.0f, 0.01f, 45.0f, window, shader.ID);

    float currentFrame = glfwGetTime();
    float lastFrame = 0.0f;

    while (!glfwWindowShouldClose(window))
    {
        currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.7f, 0.2f, 1.0f);
        cam.processInput(window, deltaTime);
        cam.mouse_callback(mouseXPos, mouseYPos);
        cam.Update();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
    }

    util::terminate();
}
