#include "window.h"

Window::Window(int32_t width, int32_t height, const std::string &title) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    this->width = width;
    this->height = height;
    this->title = title;

    if(!this->window)
        return;

    glfwMakeContextCurrent(this->window);

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
        return;

    int w, h;
    glfwGetFramebufferSize(this->window, &w, &h);
    glViewport(0, 0, w, h);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);	
}

Window::~Window() {
    glfwTerminate();
}

int Window::shouldClose() {
    return !glfwWindowShouldClose(this->window);
}

void Window::render() {
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}
