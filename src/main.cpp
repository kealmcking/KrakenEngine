// main.cpp : Defines the entry point for the application.
#include "main.h"


using namespace std;

int main()
{
	Render render;
	render.initialize(WIDTH, HEIGHT);

	// Set the window title
	render.window.setTitle("Kraken Engine");

	while(true) {
		// Main loop behavior
        //MainLoopBehaviour();
		render.renderFrame();
	}

	// Shutdown the rendering system
	render.shutdown();

	// Exit the application
	cout << "Exiting Kraken Engine..." << endl;
	return 0;
}



void MainLoopBehaviour() {
	/* Here the main loop will take place. This is not going to be an issue for a while
	* as I just want to focus on laying the foundation with mathematics and rendering first.
	*/
}
