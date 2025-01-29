#version 330 core
layout (location = 0) in vec3 vertexPos; // the position variable has attribute position 0
layout (location = 1) in vec3 vertexColorIN; // the position variable has attribute position 0
layout (location = 2) in vec2 vertexUV ; // the position variable has attribute position 0
  
out vec2 TexCoord;  // Pass to fragment shader
out vec3 FragColor;

uniform mat4 mvp;
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    //gl_Position = mvp * vec4(vertexPos, 1.0);  // see how we directly give a vec3 to vec4's constructor
    gl_Position =   model * vec4(vertexPos, 1.0); // see how we directly give a vec3 to vec4's constructor
    FragColor = vertexColorIN; // set the output variable to a dark-red color
    TexCoord = vertexUV;
}