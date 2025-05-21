#pragma once 
#include <glm/glm.hpp>
#include <string>
struct MaterialProperties {
	glm::vec3 specularColor;
	float specularStrength;
	float RefractiveIndex;
	// PBR Properties

	float metallicness;
	glm::vec3 emissive;
	float roughness;

};
struct Material {
    std::string name;
	glm::vec3 diffuseColor;
	glm::vec3 ambientColor;
	MaterialProperties properties;
	
};