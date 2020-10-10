#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>


void drawRectangle(std::vector<float> topLeft, std::vector<float> bottemRight) {
    glBegin(GL_QUADS);

    glVertex2f(topLeft.at(0), topLeft.at(1)); // top left
    glVertex2f(bottemRight.at(0), topLeft.at(1)); // top right 
    glVertex2f(bottemRight.at(0), bottemRight.at(1)); // bottom right
    glVertex2f(topLeft.at(0), bottemRight.at(1)); // bottom left
    glEnd();
}

int main(void)
{
    /* Define bounds */
    float MAXDISTANCE = 0.9f;
    float COLUMNS = 4;
    float ROWS = 3;
    float SPACING = 0.05f;
    std::vector<float> topLeft = { -0.9f, 0.9f };
    std::vector<float> topRight = { 0.9f, 0.9f };
    std::vector<float> bottemLeft = { -0.9f, -0.9f };
    std::vector<float> bottemRight = { 0.9f, -0.9f };


    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        /*Rows*/
        std::vector<float> rectangleTopleft;
        std::vector<float> rectangleBottomRight;
        for (float ii = MAXDISTANCE * 2 / ROWS; ii <= MAXDISTANCE * 2; ii += MAXDISTANCE * 2 / ROWS) {
            for (float i = MAXDISTANCE * 2 / COLUMNS; i <= MAXDISTANCE * 2; i += MAXDISTANCE * 2 / COLUMNS) {
                rectangleTopleft = { -MAXDISTANCE + SPACING + i - (MAXDISTANCE * 2 / COLUMNS), -MAXDISTANCE + SPACING + ii - (MAXDISTANCE * 2 / ROWS) };
                rectangleBottomRight = { -MAXDISTANCE + i - SPACING, -MAXDISTANCE + ii - SPACING };
                drawRectangle(rectangleTopleft, rectangleBottomRight);
            }
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}