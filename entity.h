#pragma once
#include "standard.h"
#include "config.h"
#include "util/maybe.h"
#include "facet_id.h"
#include <bitset>

struct entity_data {
	std::bitset<FACET_CAP> flags;
	char                   name[ENTITY_NAME_MAX];
};

struct entity {
	uint16_t id;

	entity(uint16_t id);
	void destroy();

	static void initialize();
	static entity spawn();
	static entity spawn(char* name);

	entity_data* data();
	char*        name();

	template <typename T>
	T* get() {
		uint16_t t = facet_id<T>::id;
		entity_data* d = data();
		bool is = d->flags[t];

		if (!is) return NULL;

		return &facet_id<T>::registry[t];
	}

	template <typename T, typename ...Args>
	T* add(Args&&... args) {
		uint16_t t = facet_id<T>::id;
		data()->flags[t] = true;
		T* v = &((facet_id<T>::registry)[t]);
		*v = T(std::forward<Args>(args)...);
		v->init(entity(id));
		return v;
	}

	template <typename T>
	void remove() {
		uint16_t t = facet_id<T>::id;
		data()->flags[t] = false;
		facet_id<T>::registry[t].destroy(entity(id));
	}
};
