#include "defaults.h"
#include "core.h"
VertexArray* Defaults::SquareSprite(){
    
    std::vector<Vertex> vertices = {
        //    POSITION                          COLOR                       UV COORD
        {glm::vec3( 0.5f,  0.5f, 0.0f),  glm::vec3(1.0f, 1.0F,1.0f), glm::vec2(0)}, // Top-right
        {glm::vec3( 0.5f, -0.5f, 0.0f),  glm::vec3(1.0f, 1.0F,1.0f), glm::vec2(0)}, // Bottom-right
        {glm::vec3(-0.5f, -0.5f, 0.0f),  glm::vec3(1.0f, 1.0F,1.0f), glm::vec2(0)}, // Bottom-left
        {glm::vec3(-0.5f,  0.5f, 0.0f),  glm::vec3(1.0f, 1.0F,1.0f), glm::vec2(0)}, // Top-left
    };
    std::vector<unsigned int> indices = {
        0, 1, 2, 
        2, 3, 0  
    };
    VertexArray* v = Core::App::Application::GetRenderer().CreateVertexArray(&vertices,&indices);
    //return std::move(v);
    return v;
}