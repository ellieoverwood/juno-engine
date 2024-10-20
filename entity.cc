#include "entity.h"
#include <queue>
#include <utility>
#include "facet.h"

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

	d->flags.reset();
	d->name[0] = '\0';
}

char* entity::name() {
	return data()->name;
}
