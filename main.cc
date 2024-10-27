#include "juno/juno.h"
#include "juno/platform/sdl_window.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include "juno/ui/ui.h"

juno::entity e;

void juno::init() {
	juno::state::window = new juno::platform::sdl_window();
	juno::state::window->create(
		"Juno Engine Build", 1280, 720, 300, 200, 3, 3
	);

	juno::facet::declare<juno::transform>();

	e = juno::entity::spawn("aaa");
	e.add<juno::transform>(glm::vec3(3.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0), glm::vec3(1, 1, 1));
	e = juno::entity::spawn();
}

void juno::update() {
	DEBUG_POINT;
}

void juno::render() {
	glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void juno::post() {
}

void juno::destroy() {
	e.destroy();
}
