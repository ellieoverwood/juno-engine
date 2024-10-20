#pragma once
#include "facet.h"

struct transform : public facet {
	transform();
	transform(glm::vec3 position);
	transform(glm::vec3 position, glm::vec3 rotation, float angle, glm::vec3 scale);

	glm::vec3 position;
	glm::vec3 rotation;
	float     angle;
	glm::vec3 scale;

	glm::mat4 matrix();
};

//FACET_H(transform);
