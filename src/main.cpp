#include "window.h"

int main(int argc, char const *argv[]) {
	Window window(1280, 720, "RPGGame");

	while(!window.shouldClose()) {
		window.render();
	}

	return 0;
}