#pragma once
#include "facet.h"

namespace juno {
struct transform : public facet {
	transform();
	transform(glm::vec3 position);
	transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	glm::mat4 matrix();
};
}