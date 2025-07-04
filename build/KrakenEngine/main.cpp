// main.cpp : Defines the entry point for the application.

#include "main.h"
#include "source/render.cpp"

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	Render render;
	render.initialize();

	// Set the window title
	render.window.setTitle("Kraken Engine - Debug");

	while(true) {
		// Main loop behavior
		MainLoopBehavoir();
		render.renderFrame();
	}

	// Shutdown the rendering system
	render.shutdown();

	// Exit the application
	cout << "Exiting Kraken Engine..." << endl;
	return 0;
}



void MainLoopBehavoir() {
	/* Here the main loop will take place. This is not going to be an issue for a while
	* as I just want to focus on laying the foundation with mathematics and rendering first.
	*/
}
