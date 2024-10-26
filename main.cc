#include "juno/entity.h"
#include "juno/facet.h"
#include "juno/transform.h"

int main() {
	jn::entity::initialize();
	jn::facet_metadata::initialize();
	jn::facet::declare<transform>();

	jn::entity e = jn::entity::spawn("aaa");
	e.add<transform>(glm::vec3(3.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0), 90, glm::vec3(1, 1, 1));
	printf("%s %f\n", e.name(), e.get<transform>()->position.x);
	//e.remove<transform>();

	e.destroy();
}
