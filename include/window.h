#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <iostream>

class Window{
public:
    void create(const char* title, int width, int height);
    
    void destroy();
    
    void setTitle(const char* newTitle);
    
    void resize(int newWidth, int newHeight);
    void clear();
    void draw();
    
    int width;
    int height;
    const char* title;
    
    GLFWwindow* window;
};

#endif

