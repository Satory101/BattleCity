#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
int g_windowSizeX = 640;
int g_windowSizeY = 480;
void gflwWindowsizecallback (GLFWwindow * window, int width, int height)
{
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport (0,0, g_windowSizeX, g_windowSizeY);
}

void gflwKeycallback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Battle city", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

glfwSetWindowSizeCallback(window, gflwWindowsizecallback);
// glfwSetKeyCallback(window, gflwKeycallback );
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if (!gladLoadGL())
    {
        std::cout << "Cant load Glad!" << std::endl;
        return -1;
    }
    std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;
    glClearColor(0,1,0,1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}