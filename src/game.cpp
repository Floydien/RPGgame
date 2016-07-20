#include "game.h"

Game::Game(const std::string &name,const std::string &vs,const std::string &fs) :
	name(name),
	window(WIDTH, HEIGHT, name),
	tile(1,1,1,1,"res/texture/ground_stone.png"),
	tile2(0,1,1,1,"res/texture/building.png"),
	shader(vs.c_str(), fs.c_str()) {

    shader.addUniform("ratio");
	shader.addUniform("offset");
}

void Game::run() {

    float aspectRatio = (float) WIDTH / (float) HEIGHT;

	while (window.shouldClose()) { 
		shader.updateUniform1f("ratio", aspectRatio);
		shader.bind();

		tile.draw(shader);
		tile2.draw(shader);
		window.render();
	}
}