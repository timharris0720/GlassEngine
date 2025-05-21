#version 330 core
in vec2 TexCoord;
in vec3 FragColor;
in vec3 FragPos;
in vec3 Normal;  


uniform sampler2D ourTexture;

out vec4 FragOutput;

float LinearizeDepth(float depth, float near, float far) {
    float z = depth * 2.0 - 1.0; // Convert [0,1] to [-1,1] (NDC)
    return (2.0 * near * far) / (far + near - z * (far - near));
}

void main() {

    float farPlane = 1000000.0f;
    float nearPlane = 0.0001f;

    float depth = gl_FragCoord.z; // Non-linear depth from default depth buffer
    float linearDepth = (2.0 * nearPlane * farPlane) / 
                        (farPlane + nearPlane - (2.0 * depth - 1.0) * (farPlane - nearPlane));

    // Normalize to [0, 1] range for viewing
    linearDepth = linearDepth / farPlane;
    
    FragColor = vec4(vec3(linearDepth), 1.0); // grayscale
}