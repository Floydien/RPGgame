#pragma once
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "vec2.h"
#include <stdint.h>
#include <GL/glew.h>

class Tile {
public:
    Tile(uint32_t x, uint32_t y, uint32_t width, uint32_t height, 
            const std::string &textureName) : 
        Tile(Vec2(x, y), Vec2(width, height), textureName) {}

    Tile(const Vec2 &pos, const Vec2 &bounds, const std::string &textureName) :
        pos(pos),
        mesh(Mesh(createVertices(bounds), createIndices(), 
            "tile_" + to_string(bounds.x) + "_" + to_string(bounds.y))),
        texture(Texture(textureName)) {}

    void draw(const Shader &);
    
    inline uint32_t getX() { return pos.x; };
    inline uint32_t getY() { return pos.y; };
    inline Vec2 getPos() { return pos; };

    inline void setX(uint32_t x) { pos.x = x; };
    inline void setY(uint32_t y) { pos.y = y; };
    inline void setPos(const Vec2 &v) { pos = v; };

protected:
    Vec2 pos;

private:
    std::vector<uint32_t> createVertices(const Vec2 &);
    std::vector<uint32_t> createIndices();

    Mesh mesh;
    Texture texture;
};
