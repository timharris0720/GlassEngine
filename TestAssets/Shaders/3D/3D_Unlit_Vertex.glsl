#version 330 core

layout (location = 0) in vec3 vertexPos; 
layout (location = 1) in vec3 vertexColorIN; 
layout (location = 2) in vec2 vertexUV; 
layout (location = 3) in vec3 vertexNormal; 
  
out vec2 TexCoord;
out vec3 FragColor;
out vec3 FragPos;
out vec3 Normal;  

uniform mat4 mvp;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

void main()
{

    FragPos = vec3(model * vec4(vertexPos, 1.0));
    // Normal = FragPos + vertexNormal;  
	vec4 tempPos = projection * view * vec4(FragPos, 1.0);
    //gl_Position =   model * vec4(vertexPos, 1.0); 
    gl_Position = tempPos; //woeld space
    //gl_Position = vec4(FragPos,1.0);   //MODEL SPACE out


    //FragPos = vec3(model * vec4(vertexPos, 1.0));
    //vec4 worldPos = projection * view * vec4(FragPos, 1.0);
    //gl_Position = mvp * vec4(vertexPos, 1.0);  
    
    FragColor = vertexColorIN;
    TexCoord = vertexUV;
    Normal = vertexNormal;
}

