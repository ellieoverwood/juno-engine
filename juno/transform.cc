#include "transform.h"

namespace juno {
FACET_DECL(transform);

transform::transform() {
	position = glm::vec3(0, 0, 0);
	rotation = glm::vec3(1, 0, 0);
	angle    = 0;
	scale    = glm::vec3(1, 1, 1);
}

transform::transform(glm::vec3 _position) {
	transform();
	position = _position;
}

transform::transform(glm::vec3 _position, glm::vec3 _rotation, float _angle, glm::vec3 _scale) {
	position = _position;
	rotation = _rotation;
	angle    = _angle;
	scale    = _scale;
}
}
