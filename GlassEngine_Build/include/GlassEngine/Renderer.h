#pragma once
#include "core.h"

struct Vertex {
    std::vector<Vector3> Position;
    std::vector<Vector2> TexCoord;
    std::vector<Vector3> Color;
    std::vector<Vector3> Normal;

};

struct RenderData {
    std::vector<Vertex> Vertices;
};



class Renderer {
public:
    Renderer() = default;
    void Init();
    void DrawObject(Core::Object::GameObject GO);
};