#version 330 core
in vec2 TexCoord;
in vec3 FragColor;
in vec3 FragPos;
in vec3 Normal;  


uniform sampler2D ourTexture;

out vec4 FragOutput; // the input variable from the vertex shader (same name and same type)  

float near = 0.1; 
float far  = 100.0; 
float LinearizeDepth(float depth) 
{
    float z = depth * 2.0 - 1.0; // back to NDC 
    return (2.0 * near * far) / (far + near - z * (far - near));	
}
void main()
{
    vec4 inputColor = vec4(FragColor, 1.0);
    vec4 textureColor = texture(ourTexture, TexCoord);

    //FragOutput = inputColor;

    //visual depth buff
    
    //float depth = LinearizeDepth(gl_FragCoord.z) / far; // divide by far for demonstration
    //FragOutput = vec4(vec3(depth), 1.0);
    
    //Default draw
    FragOutput = inputColor * textureColor;
} 