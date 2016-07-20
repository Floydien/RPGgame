#include "texture.h"
#include <GL/glew.h>
#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

std::map<const std::string, TextureData *> Texture::textureMap;

TextureData::TextureData(const std::string &name) {
    // load image in rgba format
    int width, height, channels;
    uint8_t *data = stbi_load(name.c_str(), &width, &height,
                        &channels, 4);
    if(!data)
        return;

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
                GL_RGBA, GL_UNSIGNED_BYTE, data);


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

TextureData::~TextureData() {
    glDeleteTextures(1, &textureID);
}

void TextureData::bind(uint32_t location) const {
    glActiveTexture(location);
    glBindTexture(GL_TEXTURE_2D, textureID);
}

Texture::Texture(const std::string &name) {
    std::map<const std::string, TextureData *>::iterator it = textureMap.find(name);
    if(it != textureMap.end()) {
        data = it->second;
        data->addReference();
    }
    else {
        data = new TextureData(name);
        textureMap.insert(std::pair<const std::string, TextureData *>(name, data));
    }
}

Texture::~Texture() {
    if(data->removeReference())
        delete (data);
}

void Texture::bind(uint32_t location) const {
    data->bind(location);

}