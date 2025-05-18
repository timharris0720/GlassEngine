#include "defaults.h"
#include "core.h"
VertexArray* Defaults::SquareSprite(){
    
    std::vector<Vertex> vertices = {
        //           POSITION                       COLOR              UV COORD
        {glm::vec3( 0.5f,  0.5f, 0.0f),  0, glm::vec3(0.5, 0.123, 0.4), glm::vec3(0), glm::vec2(1,1)}, // Top-right color: rgb: 128 31 102 
        {glm::vec3( 0.5f, -0.5f, 0.0f),  0, glm::vec3(0.25, 0.9, 0.4), glm::vec3(0), glm::vec2(1,0)}, // Bottom-right 63, 229, 102
        {glm::vec3(-0.5f,  0.5f, 0.0f),  0, glm::vec3(0.15, 0.2, 0.4), glm::vec3(0), glm::vec2(0,1)}, // Top-left  38, 51, 102
        {glm::vec3(-0.5f, -0.5f, 0.0f),  0, glm::vec3(0.23, 0.1, 0.4), glm::vec3(0), glm::vec2(0)}, // Bottom-left 
    };
    std::vector<unsigned int> indices = {
        2, 1, 0,   // First triangle: top-left, bottom-right, top-right
        2, 3, 1
        
    };
    VertexArray* v = Core::App::Application::GetRenderer().CreateVertexArray(&vertices,&indices);
    //return std::move(v);
    return v;
}


VertexArray* Defaults::Cube(){
    std::vector<Vertex> vertices = {
        // Front face
        {glm::vec3( 0.5f,  0.5f,  0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(1,1)}, // 0
        {glm::vec3( 0.5f, -0.5f,  0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(1,0)}, // 1
        {glm::vec3(-0.5f, -0.5f,  0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(0,0)}, // 2
        {glm::vec3(-0.5f,  0.5f,  0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(0,1)}, // 3
    
        // Back face
        {glm::vec3( 0.5f,  0.5f, -0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(0,1)}, // 4
        {glm::vec3( 0.5f, -0.5f, -0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(0,0)}, // 5
        {glm::vec3(-0.5f, -0.5f, -0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(1,0)}, // 6
        {glm::vec3(-0.5f,  0.5f, -0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(1,1)}, // 7
    };

    std::vector<unsigned int> indices = {
        // Front face
        0, 1, 2,
        2, 3, 0,
    
        // Right face
        0, 4, 5,
        5, 1, 0,
    
        // Back face
        4, 7, 6,
        6, 5, 4,
    
        // Left face
        3, 2, 6,
        6, 7, 3,
    
        // Top face
        0, 3, 7,
        7, 4, 0,
    
        // Bottom face
        1, 5, 6,
        6, 2, 1
    };
    VertexArray* v = Core::App::Application::GetRenderer().CreateVertexArray(&vertices,&indices);
    return v;

}