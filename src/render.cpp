#include "render.h"


void Render::initialize(int width, int height) {
    // Implementation for initializing the rendering syste
    window.create("Kraken Engine", width, height);
        }

void Render::renderFrame() {
    // Implementation for rendering a single frame
    window.draw();
    
    
    // Clear the window at the end of the frame
    window.clear();
}

void Render::shutdown() {
    // Implementation for shutting down the rendering system
    window.destroy();
}


