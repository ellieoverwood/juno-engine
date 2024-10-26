#include "flow.h"
#include "entity.h"
#include "facet_id.h"

using namespace juno;

int main() {
	entity::initialize();
	facet_metadata::initialize();

	init();
	for (;;) {
		update();
		render();
		post();
	}
	destroy();
}
