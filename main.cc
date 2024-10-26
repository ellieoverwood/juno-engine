#include "juno/juno.h"
#include "juno/platform/sdl_window.h"

juno::entity e;

void juno::init() {
	juno::state::window = new juno::platform::sdl_window();
	juno::state::window->create(
		"Juno Engine Build", 1280, 720, 300, 200, 3, 3
	);

	juno::facet::declare<juno::transform>();

	e = juno::entity::spawn("aaa");
	e.add<juno::transform>(glm::vec3(3.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0), 90, glm::vec3(1, 1, 1));
}

void juno::update() {
}

void juno::render() {
}

void juno::post() {
}

void juno::destroy() {
	e.destroy();
}
