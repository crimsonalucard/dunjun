#include <iostream>
#include <string>
#include <Dunjun/Common.hpp>
#include <GL/glew.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#include <GLFW/glfw3.h>

#define GLOBAL static
#define internal static
#define LOCAL_PERSIST static

#define float32 float
#define float64 double

GLOBAL const int g_windowWidth = 854;
GLOBAL const int g_windowHeight = 480;
GLOBAL const char* g_gameTitle = "Dunjun";

GLFWwindow *toggleFullScreenWindow(GLFWwindow *window, int key);

void setColor(float32 red, float32 blue, float32 green, float32 alpha);

bool toggleExit(GLFWwindow *window, bool isRunning);

GLFWwindow* initialize_window(int width, int height, const char* title);

void init_glew();

int main(int argc, char **argv) {

    init_glew();

    GLFWwindow *window = initialize_window(g_windowWidth, g_windowHeight, g_gameTitle);

    bool running = true;
    /* Loop until the user closes the window */
    while (running) {

        /* Render here */
        setColor(0.5f, 0.69f, 1.0f, 1.0f);

        /*Swap front and back buffers */
        glfwSwapBuffers(window);

        /*poll for and process events*/
        glfwPollEvents();

        running = toggleExit(window, running);

        window = toggleFullScreenWindow(window, GLFW_KEY_F11);
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}







void setColor(float32 red, float32 blue, float32 green, float32 alpha){
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool toggleExit(GLFWwindow *window, bool isRunning) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) ||
        glfwWindowShouldClose(window)) {
        isRunning = false;
    }

    return isRunning;
}

GLFWwindow* initialize_window(int width, int height, const char* title){
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow *window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    return window;
}

GLFWwindow *toggleFullScreenWindow(GLFWwindow *window, int key) {
    if (glfwGetKey(window, key)) {
        LOCAL_PERSIST bool isFullScreen = false;
        isFullScreen = !isFullScreen;

        GLFWwindow *newWindow;
        if (isFullScreen) {
            int count;
            const GLFWvidmode *modes = glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);
            int monitorHeight = modes[count - 1].height;
            int monitorWidth = modes[count - 1].width;
            newWindow = glfwCreateWindow(monitorWidth, monitorHeight, g_gameTitle, glfwGetPrimaryMonitor(), window);
        } else {
            newWindow = glfwCreateWindow(g_windowWidth, g_windowHeight, g_gameTitle, nullptr, window);
        }
        glfwDestroyWindow(window);
        glfwMakeContextCurrent(newWindow);
        return newWindow;


    }
}

void init_glew(){
    //apple doesn't need this call.
#ifndef __APPLE__
    if(!glewInit()){
        exit(EXIT_FAILURE);
    }
#endif
}