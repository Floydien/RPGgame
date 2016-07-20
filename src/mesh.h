#pragma once
#include "referencecounter.h"
#include <vector>
#include <GL/glew.h>
#include <map>

using namespace std;

class MeshData : public ReferenceCounter {
public:
	MeshData(const std::vector<uint32_t> &, const std::vector<uint32_t> &);
	~MeshData();

	void draw() const;
private:
    uint32_t vao;
    uint32_t vbo;
    uint32_t ebo;
};

class Mesh {
public:
	Mesh(const std::vector<uint32_t> &, const std::vector<uint32_t> &, const std::string &);
	~Mesh();

    void draw() const;

private:
	const std::string name;

    MeshData *data;

    static std::map<const std::string, MeshData *> meshMap;
};