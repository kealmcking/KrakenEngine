#ifndef RENDER_H
#define RENDER_H

#include "window.h"


class Render {
public:
    void initialize(int width, int height);

    void renderFrame();
    
    void shutdown();
    Window window;
};

#endif
