#include "defaults.h"
#include "core.h"
VertexArray* Defaults::SquareSprite(glm::vec2 scalingWidth){
    
    std::vector<Vertex> vertices = {
        //           POSITION                       COLOR              UV COORD
        {glm::vec3( 0.5f,  0.5f, 0),  0, glm::vec3(1), glm::vec3(0), glm::vec2(1*scalingWidth.x,1*scalingWidth.y)}, // Top-right color: rgb: 128 31 102 
        {glm::vec3(-0.5f, -0.5f, 0),  0, glm::vec3(1), glm::vec3(0), glm::vec2(0*scalingWidth.x,0*scalingWidth.y)}, // Bottom-left 
        {glm::vec3( 0.5f, -0.5f, 0),  0, glm::vec3(1), glm::vec3(0), glm::vec2(1*scalingWidth.x,0*scalingWidth.y)}, // Bottom-right 63, 229, 102
        {glm::vec3(-0.5f,  0.5f, 0),  0, glm::vec3(1), glm::vec3(0), glm::vec2(0*scalingWidth.x,1*scalingWidth.y)}, // Top-left  38, 51, 102
    };
    std::vector<unsigned int> indices = {
        0,1,2,
        0,1,3
        
    };
    VertexArray* v = Core::App::Application::GetRenderer().CreateVertexArray(&vertices,&indices);
    //return std::move(v);
    return v;
}
VertexArray* Defaults::Circle(float radius, int segments, glm::vec2 scalingWidth){
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    glm::vec3 color(1.0f);   // white
    glm::vec3 normal(0.0f, 0.0f, 0.0f); // facing out of screen (Z+)

    vertices.push_back({
        glm::vec3(0.0f, 0.0f, 0.0f),
        0,
        color,
        normal,
        glm::vec2(0.5f * scalingWidth.x, 0.5f * scalingWidth.y) // center of texture
    });
    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * glm::pi<float>() * i / segments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
    
        // UV from [-0.5, 0.5] mapped to [0,1]
        float u = (x + 0.5f) * scalingWidth.x;
        float v = (y + 0.5f) * scalingWidth.y;
    
        vertices.push_back({
            glm::vec3(x, y, 0.0f),
            0,
            color,
            normal,
            glm::vec2(u, v)
        });
    
        // Indices for triangle fan
        if (i > 0) {
            indices.push_back(0);        // center
            indices.push_back(i);
            indices.push_back(i + 1);
        }
    }
    VertexArray* v = Core::App::Application::GetRenderer().CreateVertexArray(&vertices,&indices);
    return v;
}

VertexArray* Defaults::Cube(glm::vec2 scalingWidth){
    std::vector<Vertex> vertices = {
        // Front face
        {glm::vec3( 0.5f,  0.5f,  0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(1*scalingWidth.x,1*scalingWidth.y)}, // 0
        {glm::vec3( 0.5f, -0.5f,  0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(0*scalingWidth.x,0*scalingWidth.y)}, // 1
        {glm::vec3(-0.5f, -0.5f,  0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(1*scalingWidth.x,0*scalingWidth.y)}, // 2
        {glm::vec3(-0.5f,  0.5f,  0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(0*scalingWidth.x,1*scalingWidth.y)}, // 3
    
        // Back face
        {glm::vec3( 0.5f,  0.5f, -0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(1*scalingWidth.x,1*scalingWidth.y)}, // 4
        {glm::vec3( 0.5f, -0.5f, -0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(0*scalingWidth.x,0*scalingWidth.y)}, // 5
        {glm::vec3(-0.5f, -0.5f, -0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(1*scalingWidth.x,0*scalingWidth.y)}, // 6
        {glm::vec3(-0.5f,  0.5f, -0.5f),  0,glm::vec3(1,1,1), glm::vec3(0), glm::vec2(0*scalingWidth.x,1*scalingWidth.y)}, // 7
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