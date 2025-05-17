#pragma once 
#include <glm/glm.hpp>
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
	glm::vec3 diffuseColor;
	glm::vec3 ambientColor;
	MaterialProperties properties;
	
};