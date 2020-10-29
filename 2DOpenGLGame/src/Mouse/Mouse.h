#pragma once
#include <GLFW\glfw3.h>
#include <iostream>
#ifndef MOUSE_H
#define MOUSE_H
static bool clicked;
static double xpos, ypos;
void mouseCursor(GLFWwindow * window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        //getting cursor position
        glfwGetCursorPos(window, &xpos, &ypos);
        clicked = true;
    }
};
void setMouseCallBack(GLFWwindow * window) {
    glfwSetMouseButtonCallback(window, mouseCursor);
};

#endif