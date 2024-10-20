#include "entity.h"
#include "facet.h"
#include "transform.h"

int main() {
	entity::initialize();
	facet_metadata::initialize();
	facet::declare<transform>();

	entity e = entity::spawn("aaa");
	e.add<transform>(glm::vec3(3.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0), 90, glm::vec3(1, 1, 1));
	printf("%s %f\n", e.name(), e.get<transform>()->position.x);
	//e.remove<transform>();

	e.destroy();
}
