#pragma once
#include <GL/glew.h>
#include <vector>
#include <assimp/mesh.h>

class Mesh {
public:
    Mesh();
    ~Mesh();

    void loadFromAssimpMesh(aiMesh* mesh);
    void render();

private:
    GLuint VAO, VBO, EBO;
    unsigned int numIndices;

    void setupMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
};
