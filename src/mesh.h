#pragma once
#include "referencecounter.h"
#include <vector>
#include <GL/glew.h>
#include <map>

using namespace std;

class MeshData : public ReferenceCounter
{
public:
	MeshData(const vector<uint32_t> &, const vector<uint32_t> &);
	~MeshData();

	void draw() const;
private:
    uint32_t vao;
    uint32_t vbo;
    uint32_t ebo;
};

class Mesh
{
public:
	Mesh(const vector<uint32_t> &, const vector<uint32_t> &, const string &);
	~Mesh();

    void draw() const;

private:
	const string name;

    MeshData *data;

    static map<const string, MeshData *> meshMap;
};