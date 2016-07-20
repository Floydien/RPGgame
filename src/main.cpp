#include "window.h"
#include "shader.h"
#include "mesh.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

const GLchar* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec2 position;\n"
    "layout (location = 1) in vec2 uv;\n"
    "uniform float ratio;\n"
    "out vec2 uvCoords;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4((position.x) / (ratio * 2) - 1, "
    "(position.y) / 2 - 1, 0.0, 1.0);\n"
    "uvCoords = uv;\n"
    "}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
    "in vec2 uvCoords;\n"
    "out vec4 color;\n"
    "uniform sampler2D textureData;\n"
    "void main()\n"
    "{\n"
    "vec4 tile = texture(textureData, uvCoords);\n"
    "//color = tile;\n"
    "color = vec4(1,0,0,1);\n"
    "}\n\0";


int main(int argc, char const *argv[]) {

    std::vector<uint32_t> v(16);
    std::vector<uint32_t> i(6);
    v = {
        0, 0, 1, 1,
        1, 0, 0, 1,
        0, 1, 1, 0,
        1, 1, 0, 0 
    };
    i = {
        0, 1, 2,
        2, 1, 3 
    };
	Window window(WIDTH, HEIGHT, "RPGGame");

    Mesh mesh(v, i, "tile_" + to_string(1) + "_" + to_string(1));

    Shader shader(vertexShaderSource, fragmentShaderSource);
    shader.addUniform("ratio");
    float aspectRatio = (float) WIDTH / (float) HEIGHT;


	while(!window.shouldClose()) {
        shader.updateUniform1f("ratio", aspectRatio);
        shader.bind();

		mesh.draw();

		window.render();
	}

	return 0;
}