#include "defaults.h"
#include "core.h"
VertexArray* Defaults::SquareSprite(){
    
    Vertex Vertex1;
    Vertex1.vertices = glm::vec3(-0.5f, -0.5f,0.0f);
    Vertex1.color = glm::vec3(1,1,1);
    Vertex Vertex2;
    Vertex2.vertices = glm::vec3(0.5f, -0.5f,0.0f);
    Vertex2.color = glm::vec3(1,1,1);
    Vertex Vertex3;
    Vertex3.vertices = glm::vec3(0.5f,  0.5f,0.0f);
    Vertex3.color = glm::vec3(1,1,1);
    Vertex Vertex4;
    Vertex4.vertices = glm::vec3( -0.5f,  0.5f ,0.0f);
    Vertex4.color = glm::vec3(1,1,1);
    std::vector<Vertex> vertices = {
        Vertex1,Vertex2,Vertex3,Vertex4
    };
    std::vector<unsigned int> indices = {
        0, 1, 2, 
        2, 3, 0  
    };
    VertexArray* v = Core::App::Application::GetRenderer().CreateVertexArray(&vertices,&indices);
    Core::App::Application::GetInstance().getLogger().InfoLog("Vertex Array Created");
    //return std::move(v);
    return v;
}