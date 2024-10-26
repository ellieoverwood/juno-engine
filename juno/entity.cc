#include "entity.h"
#include <queue>
#include <utility>
#include "facet.h"

namespace juno {
entity_data entities[ENTITY_CAP] = {};
std::queue<entity> available_ids;

entity::entity(uint16_t _id) {
	id = _id;
}

void entity::initialize() {
	for (int i = 0; i < ENTITY_CAP; i ++) {
		available_ids.push(i);
	}
}

entity entity::spawn() {
	entity e = available_ids.front();
	e.data()->flags[0] = true;
	available_ids.pop();
	return e;
}

entity entity::spawn(char* name) {
	entity e = spawn();
	strcpy(e.data()->name, name);
	return e;
}

entity_data* entity::data() {
	return &entities[id];	
}

void entity::destroy() {
	available_ids.push(id);
	entity_data* d = data();

	for (int i = 1; i < FACET_CAP; i ++) {
		if (d->flags[i]) at(i)->destroy(id);
	}

	d->flags.reset();
	d->name[0] = '\0';
}

char* entity::name() {
	return data()->name;
}

facet* entity::at(uint16_t facet_id) {
	facet_metadata m = internal_state::facet_metadata_arr[facet_id];
	return (facet*)(&((char*)m.registry)[m.size * id]);
}

bool entity::active() {
	return data()->flags[0];	
}

void entity::enable() {
	data()->flags[0] = true;
}

void entity::disable() {
	data()->flags[0] = false;
}

void entity::toggle() {
	data()->flags[0] = !active();
}

}
