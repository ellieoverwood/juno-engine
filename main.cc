#include "juno/juno.h"

juno::entity e;

void juno::init() {
	juno::facet::declare<juno::transform>();

	e = juno::entity::spawn("aaa");
	e.add<juno::transform>(glm::vec3(3.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0), 90, glm::vec3(1, 1, 1));
}

void juno::update() {
	printf("%s %f\n", e.name(), e.get<juno::transform>()->position.x);
}

void juno::render() {
}

void juno::post() {
}

void juno::destroy() {
	e.destroy();
}
