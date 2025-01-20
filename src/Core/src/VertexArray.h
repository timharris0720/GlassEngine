#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
struct Vertex {
    glm::vec3 vertices;
    glm::vec3 color;
    glm::vec2 UV;
};
// TODO add Layouts
class VertexArray{
    public:
    unsigned int VAO, VBO, EBO;
    unsigned int IndiciesCount;
    VertexArray() = default;
    virtual void Bind(){};
    virtual void Unbind(){};
    virtual void Create(std::vector<Vertex>* verts,std::vector<unsigned int>* inds) {};
};