#include "window.h"

// Methods for window management
void Window::create(const char* startTitle, int startWidth, int startHeight) {
    
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
    }
    // Implementation for creating a window
    Window::width = startWidth;
    Window::height = startHeight;
    Window::title = startTitle;
    
    Window::window = glfwCreateWindow(width, height, title, NULL, NULL);
    
    glfwMakeContextCurrent(window);
}

void Window::destroy() {
    // Implementation for destroying a window
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::setTitle(const char* newTitle) {
    // Implementation for setting the window title
    Window::title = newTitle;
}

void Window::resize(int newWidth, int newHeight) {
    // Implementation for resizing the window
    Window::width = newWidth;
    Window::height = newHeight;
    
    glfwSetWindowSize(window, width, height);
}

void Window::clear() {
    // Implementation for clearing the window
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::draw() {
    // Implementation for drawing objects on the window
}
