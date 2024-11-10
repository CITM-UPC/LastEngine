#pragma once
#include <string>
#include "Components/Mesh.h"
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

class ModelLoader {
public:
    ModelLoader() = default;
    ~ModelLoader() = default;

    bool loadModel(const std::string& path, Mesh& outMesh);

private:
    void processNode(aiNode* node, const aiScene* scene, Mesh& outMesh);
    void processMesh(aiMesh* mesh, Mesh& outMesh);
};
