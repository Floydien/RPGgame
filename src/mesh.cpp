#include "mesh.h"
#include <cstdio>

std::map<const std::string, MeshData *> Mesh::meshMap;

MeshData::MeshData(const std::vector<uint32_t> &vertices, const std::vector<uint32_t> &indices) :
    ReferenceCounter() {

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(uint32_t) * vertices.size(),
            &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo); 
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * indices.size(),
            &indices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_UNSIGNED_INT, GL_FALSE, 4 * sizeof(float),
                            (void *) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_UNSIGNED_INT, GL_FALSE, 4 * sizeof(float),
                            (void *) (2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

MeshData::~MeshData() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}

void MeshData::draw() const {
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

Mesh::Mesh(const std::vector<uint32_t> &vertices, const std::vector<uint32_t> &indices, const std::string &name) :
    name(name) {
    std::map<const std::string, MeshData *>::iterator it = meshMap.find(name);
    if(it != meshMap.end())
    {
        data = it->second;
        data->addReference();
    }
    else
    {
        data = new MeshData(vertices, indices);
        meshMap.insert(std::pair<const string, MeshData *>(name, data));
    }
    printf("%s\n", name.c_str());
}

Mesh::~Mesh() {
    if(data->removeReference())
        delete (data);
}

void Mesh::draw() const {
    data->draw();
}