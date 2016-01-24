#include <iostream>
#include <string>
#include <Dunjun/Common.hpp>
#include <GLFW/glfw3.h>
#include <string>

#define global static
#define internal static
#define local_persist static

global const int g_windowWidth = 854;
global const int g_windowHeight = 480;
global const std::string g_gameTitle = "Dunjun";

int main(int argc, char ** argv) {
    GLFWwindow* window;

    /* Initialize the Library */

    if(!glfwInit()){
        return EXIT_FAILURE;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(g_windowWidth, g_windowHeight, "Dunjun", nullptr, nullptr);
    if(!window){
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    bool running = true;
    bool fullscreen = false;
    /* Loop until the user closes the window */
    while(running){

        /* Render here */
        glClearColor(0.5f, 0.69f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /*Swap front and back buffers */
        glfwSwapBuffers(window);

        /*poll for and process events*/
        glfwPollEvents();

        if(glfwGetKey(window, GLFW_KEY_ESCAPE) ||
           glfwWindowShouldClose(window)){
            running = false;
        }

        if(glfwGetKey(window, GLFW_KEY_F11)){
            fullscreen = !fullscreen;
            GLFWwindow* newWindow;
            if (fullscreen){
                newWindow = glfwCreateWindow(1440, 900, "Dunjun", glfwGetPrimaryMonitor(),  window);
            } else {
                newWindow = glfwCreateWindow(g_windowWidth, g_windowHeight, "Dunjun", nullptr, window);
            }
            glfwDestroyWindow(window);
            window = newWindow;
            glfwMakeContextCurrent(window);



        }
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}