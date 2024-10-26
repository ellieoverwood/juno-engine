#include "flow.h"
#include "entity.h"
#include "facet_id.h"
#include "window.h"

using namespace juno;
juno::window* juno::state::window;

int main() {
	entity::initialize();
	facet_metadata::initialize();

	init();
	for (;;) {
		state::window->poll();
		if (state::window->to_terminate) break;
		update();
		render();
		post();
		state::window->swap();
	}
	destroy();
	state::window->terminate();
}
