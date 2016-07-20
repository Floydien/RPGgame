#pragma once
#include "window.h"
#include "tile.h"
#include "shader.h"
#include <string>

class Game {
public:
	Game(const std::string &,const std::string &,const std::string &);

	void run();
private:
	std::string name;
	Window window;
	Tile tile;
	Tile tile2;
	Shader shader;

	static const int WIDTH = 1280;
	static const int HEIGHT = 720;
};