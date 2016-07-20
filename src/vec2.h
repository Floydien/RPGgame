#pragma once
#include <stdint.h>

class Vec2
{
public:
	Vec2(uint32_t x = 0, uint32_t y = 0) :
			x(x), y(y) {};

	uint32_t x, y;

	inline bool operator==(const Vec2 &other) { return x == other.x && y == other.y; };
	inline bool operator!=(const Vec2 &other) { return x != other.x || y != other.y; };
private:
};
