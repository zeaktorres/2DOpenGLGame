#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>
#include <stdlib.h> 
#include "Grid/Grid.h"
#include "Timer/Timer.h"
#include "GameLogic/GameLogic.h"
#include <string>
int main(void)
{
    /* Define bounds */
    float MAXDISTANCE = 0.9f;
    float COLUMNS = 4;
    float ROWS = 4;
    float SPACING = 0.05f;
    int WINDOW_WIDTH = 640;
    int WINDOW_LENGTH = 480;
    std::vector<int> COLORS = std::vector<int>{ 255, 255, 255 };
    std::vector<float> topLeft = { -0.9f, 0.9f };
    std::vector<float> topRight = { 0.9f, 0.9f };
    std::vector<float> bottemLeft = { -0.9f, -0.9f };
    std::vector<float> bottemRight = { 0.9f, -0.9f };
    bool draw = false;

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_LENGTH, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    GameLogic game = GameLogic(MAXDISTANCE, ROWS, COLUMNS, SPACING, COLORS, window, WINDOW_LENGTH, WINDOW_WIDTH);
    game.start();
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        /* Draw */
        game.play();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}