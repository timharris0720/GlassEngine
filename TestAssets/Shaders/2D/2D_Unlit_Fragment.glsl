#version 330 core
in vec2 TexCoord;
in vec3 FragColor;
in vec3 FragPos;
in vec3 Normal;  


uniform sampler2D ourTexture;

out vec4 FragOutput;
void main()
{
    vec4 inputColor = vec4(FragColor, 1.0);
    //vec4 inputColor = vec4(testColor, 1.0);
    vec4 textureColor = texture(ourTexture, TexCoord);
    //FragOutput = inputColor * textureColor;
    FragOutput = inputColor;
} 