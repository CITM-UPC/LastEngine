#include "ModelLoader.h"
#include <iostream>

bool ModelLoader::loadModel(const std::string& path, Mesh& outMesh) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "Error cargando modelo: " << importer.GetErrorString() << std::endl;
        return false;
    }

    processNode(scene->mRootNode, scene, outMesh);
    return true;
}

void ModelLoader::processNode(aiNode* node, const aiScene* scene, Mesh& outMesh) {
    std::cout << "Nodo: " << node->mName.C_Str() << std::endl;
    std::cout << "Número de mallas en el nodo: " << node->mNumMeshes << std::endl;

    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        processMesh(mesh, outMesh);
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene, outMesh);
    }
}

void ModelLoader::processMesh(aiMesh* mesh, Mesh& outMesh) {
    std::cout << "Malla: " << mesh->mName.C_Str() << std::endl;
    std::cout << "Número de vértices: " << mesh->mNumVertices << std::endl;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        aiVector3D vertex = mesh->mVertices[i];
        std::cout << "Vértice " << i << ": (" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")" << std::endl;
    }

    std::cout << "Número de caras: " << mesh->mNumFaces << std::endl;
    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        std::cout << "Cara " << i << " - Índices: ";
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            std::cout << face.mIndices[j] << " ";
        }
        std::cout << std::endl;
    }

    outMesh.loadFromAssimpMesh(mesh);
}
