#pragma once
#include <stdint.h>

class ReferenceCounter
{
public:
	ReferenceCounter() :
		referenceCount(1) {};

	inline void addReference() { referenceCount++; };
	inline bool removeReference() { return --referenceCount == 0; }
private:
	uint32_t referenceCount;
};