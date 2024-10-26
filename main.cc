#include "juno/entity.h"
#include "juno/facet.h"
#include "juno/transform.h"

int main() {
	juno::entity::initialize();
	juno::facet_metadata::initialize();
	juno::facet::declare<juno::transform>();

	juno::entity e = juno::entity::spawn("aaa");
	e.add<juno::transform>(glm::vec3(3.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0), 90, glm::vec3(1, 1, 1));
	printf("%s %f\n", e.name(), e.get<juno::transform>()->position.x);
	//e.remove<transform>();

	e.destroy();
}
