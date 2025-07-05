

class Render {
    public:
        Window window;
        void initialize(int width = 800, int height = 600) {
            // Implementation for initializing the rendering syste
            window.create("Kraken Engine - Debug", width, height);
        }

        void renderFrame() {
            // Implementation for rendering a single frame
            window.draw();
            
            
            // Clear the window at the end of the frame
            window.clear();
        }

        void shutdown() {
            // Implementation for shutting down the rendering system
            window.destroy();
        }
};

class Window {
    public:
        // Methods for window management
        void create(const char* title, int width, int height) {
            // Implementation for creating a window
        }

        void destroy() {
            // Implementation for destroying a window
        }

        void setTitle(const char* title) {
            // Implementation for setting the window title
        }

        void resize(int width, int height) {
            // Implementation for resizing the window
        }

        void clear() {
            // Implementation for clearing the window
        }

        void draw() {

        }
}
