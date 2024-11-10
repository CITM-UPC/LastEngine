//#ifndef GAMEOBJECT_H
//#define GAMEOBJECT_H
//
//#include <vector>
//#include "Components/Transform.h"
//#include "Components/Material.h"
//#include "Components/Mesh.h"
//
//class GameObject {
//public:
//    GameObject();
//    ~GameObject();
//
//    void Start();
//    void Update();
//    void AddMesh(Mesh* newMesh);
//    void SetMaterial(Material* newMaterial);
//    void AddComponent(Component* component);
//    UINT16 GetUID() const;
//
//private:
//    Transform* transform;
//    Material* material;
//    std::vector<Component*> components;
//    std::vector<Mesh*> meshes;
//    UINT16 uid;
//
//    uint32_t LCG();
//    static uint32_t seed;
//    static const uint32_t a = 1664525;
//    static const uint32_t c = 1013904223;
//    static const uint32_t m = 4294967296;
//};
//
//#endif // GAMEOBJECT_H
