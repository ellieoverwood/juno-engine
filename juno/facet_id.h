#pragma once
#include "standard.h"
#include <vector>

namespace juno {

struct facet_metadata {
	void*    registry;
	uint16_t size;
	char*    name;

	static void initialize();
};

namespace internal_state {
	extern facet_metadata* facet_metadata_arr;
}

template <typename T>
struct facet_id {
	static uint16_t id;
};

#define FACET_DECL(T)\
template <>\
uint16_t facet_id<T>::id = __COUNTER__ + 1;\
T __registry[ENTITY_CAP];\
template <>\
void facet::declare<T>() {\
	juno::internal_state::facet_metadata_arr[facet_id<T>::id].registry = (void*)__registry;\
	juno::internal_state::facet_metadata_arr[facet_id<T>::id].size = sizeof(T);\
	juno::internal_state::facet_metadata_arr[facet_id<T>::id].name = #T;\
}

}
