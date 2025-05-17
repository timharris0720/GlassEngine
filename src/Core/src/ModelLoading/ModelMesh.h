#pragma once
#ifdef _WIN32
#ifdef GLASS_ENGINE_EXPORTS_CORE
#define GLASS_ENGINE_API __declspec(dllexport)
#else
#define GLASS_ENGINE_API __declspec(dllimport)
#endif
#else
#define GLASS_ENGINE_API
#endif
#include "../VertexArray.h"
#include "Material.h"
class ModelMesh {
    public:
    ModelMesh* rootModelMesh;
    ModelMesh* parent;
    VertexArray* VA;
    
    GLASS_ENGINE_API ModelMesh();
    
};