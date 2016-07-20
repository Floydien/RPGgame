#include "window.h"
#include "mesh.h"

int main(int argc, char const *argv[]) {
	Window window(1280, 720, "RPGGame");

	std::vector<uint32_t> v(16);
    v =
    {
        0, 0,           1, 1,
        1, 0,       0, 1,
        0, 1,      1, 0,
        1, 1,  0, 0
    };

    std::vector<uint32_t> i(6);
    i =
    {
        0, 1, 2,
        2, 1, 3
    };

    Mesh mesh(v, i, "tile_" + to_string(1) + "_" + to_string(1));

	while(!window.shouldClose()) {
		mesh.draw();

		window.render();
	}

	return 0;
}