#include "flow.h"
#include "entity.h"
#include "facet_id.h"
#include "window.h"
#include "facet.h"
#include "ui/ui.h"
#include <SDL_opengl.h>

using namespace juno;
juno::window* juno::state::window;

std::vector<entity>* entity_list;

int main() {
	entity::initialize();
	facet_metadata::initialize();

	init();

	for (;;) {
		state::window->poll();
		ui::update();
		if (state::window->to_terminate) break;
	
		update();

		for (int i = 0; i < internal_state::entity_list.size(); i ++) {
			entity e = internal_state::entity_list[i];
			std::bitset<FACET_CAP + 1> flags = e.data()->flags;
			for (int j = 1; j < FACET_CAP + 1; j ++) {
				if (flags[j]) {
					((facet*)(e.at(j)))->update(e);
				}
			}
		}

		render();

		for (int i = 0; i < internal_state::entity_list.size(); i ++) {
			entity e = internal_state::entity_list[i];
			std::bitset<FACET_CAP + 1> flags = e.data()->flags;
			for (int j = 1; j < FACET_CAP + 1; j ++) {
				if (flags[j]) {
					((facet*)(e.at(j)))->render(e);
				}
			}
		}

		post();
		state::window->swap();
	}

	destroy();
	for (int i = 0; i < internal_state::entity_list.size(); i ++) {
		entity e = internal_state::entity_list[i];
		std::bitset<FACET_CAP + 1> flags = e.data()->flags;
		for (int j = 1; j < FACET_CAP + 1; j ++) {
			if (flags[j]) {
				((facet*)(e.at(j)))->destroy(e);
			}
		}
	}
	state::window->terminate();
}
