#include "window.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "game.h"

    const int WIDTH = 1280;
    const int HEIGHT = 720;

const GLchar* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec2 position;\n"
    "layout (location = 1) in vec2 uv;\n"
    "uniform float ratio;\n"
    "uniform vec2 offset;\n"
    "out vec2 uvCoords;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4((position.x + offset.x) / (ratio * 2) - 1, "
    "(position.y + offset.y) / 2 - 1, 0.0, 1.0);\n"
    "uvCoords = uv;\n"
    "}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
    "in vec2 uvCoords;\n"
    "out vec4 color;\n"
    "uniform sampler2D textureData;\n"
    "void main()\n"
    "{\n"
    "vec4 tile = texture(textureData, uvCoords);\n"
    "color = tile;\n"
    "}\n\0";


int main(int argc, char const *argv[]) {

    Game game("Hi", vertexShaderSource, fragmentShaderSource);
    game.run();
    
	return 0;
}