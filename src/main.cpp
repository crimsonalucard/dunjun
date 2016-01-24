#include <iostream>
#include <Dunjun/Common.hpp>
#include <GLFW/glfw3.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

int main(int argc, char ** argv) {
    GLFWwindow* window;

    /* Initialize the Library */

    if(!glfwInit()){
        return EXIT_FAILURE;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(854, 480, "Dunjun", nullptr, nullptr);
    if(!window){
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while(!glfwWindowShouldClose(window)){
        /* Render here */
        glClearColor(0.5f, 0.69f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /*Swap front and back buffers */
        glfwSwapBuffers(window);

        /*poll for and process events*/
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}