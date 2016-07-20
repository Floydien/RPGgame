#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <string>

class Window {
public:
    Window(int32_t, int32_t, const char *);
    ~Window();

    int shouldClose();
    void render();

    inline GLFWwindow *getWindow() { return window; };
private:
    GLFWwindow *window;
    int32_t width;
    int32_t height;
    const char *title;
};