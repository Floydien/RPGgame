#pragma once
#include <stdint.h>
#include <map>
#include <string>
#include "referencecounter.h"

class TextureData : public ReferenceCounter {
public:
	TextureData(const std::string &);
	~TextureData();

	void bind(uint32_t) const;
private:
    uint32_t textureID;
};

class Texture {
public:
    Texture(const std::string &);
    ~Texture();

    void bind(uint32_t) const;
private:
	TextureData *data;

	static std::map<const std::string, TextureData *> textureMap;
};
