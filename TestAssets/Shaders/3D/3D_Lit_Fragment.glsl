#version 330 core
in vec2 TexCoord;
in vec3 FragColor;
in vec3 FragPos;
in vec3 Normal;  


struct LightingData {
    int type;
    float intensity;
    vec3 color;
    float ambientStrength;
};

uniform LightingData light;


uniform sampler2D ourTexture;






out vec4 FragOutput;
void main()
{
    vec4 inputColor = vec4(FragColor * light.color, 1.0);
    vec4 textureColor = texture(ourTexture, TexCoord);
    FragOutput = inputColor * textureColor;
} 