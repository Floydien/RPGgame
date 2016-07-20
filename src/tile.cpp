#include "tile.h"
#include <stdio.h>

std::vector<uint32_t> Tile::createVertices(const Vec2 &bounds) {
    vector<uint32_t> v(16);
    v = {
        0, 0,               1, 1,
        bounds.x, 0,        0, 1,
        0, bounds.y,        1, 0,
        bounds.x, bounds.y, 0, 0
    };
    return v;
}
std::vector<uint32_t> Tile::createIndices() {
    vector<uint32_t> i(6);
    i = {
        0, 1, 2,
        2, 1, 3
    };
    return i;
}

void Tile::draw(const Shader &s) {
    s.updateUniform2f("offset", pos.x, pos.y);

    texture.bind(GL_TEXTURE0);
    mesh.draw();
}
