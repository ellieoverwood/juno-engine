#pragma once
#include "standard.h"
#include <vector>

namespace juno {
/*enum class facet_metadata_field_type {
	FLOAT,
};

struct facet_metadata_field {
	char* name;
	facet_metadata_field_type type;
	uint16_t offset;
};*/

struct facet_metadata {
	void*    registry;
	uint16_t size;
	char*    name;
//	std::vector<facet_metadata_field> fields;

	static void initialize();
};

namespace state {
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
	state::facet_metadata_arr[facet_id<T>::id].registry = (void*)__registry;\
	state::facet_metadata_arr[facet_id<T>::id].size = sizeof(T);\
	state::facet_metadata_arr[facet_id<T>::id].name = #T;\
}

}
