#version 330 core
in vec2 TexCoord;
in vec3 FragColor;

out vec4 FragOutput; // the input variable from the vertex shader (same name and same type)  

void main()
{
    FragOutput = vec4(FragColor,1.0);
} 