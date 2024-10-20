#pragma once
#include "standard.h"
#include "config.h"

struct facet_metadata {
	void* registry;
	uint16_t size;

	static void initialize();
};

extern facet_metadata* facet_metadata_arr;

template <typename T>
struct facet_id {
	static uint16_t id;
};

//#define FACET_H(T) template class facet_id<T>;

#define FACET_DECL(T)\
template <>\
uint16_t facet_id<T>::id = __COUNTER__;\
T __registry[ENTITY_CAP];\
template <>\
void facet::declare<T>() {\
	facet_metadata_arr[facet_id<T>::id].registry = (void*)__registry;\
	facet_metadata_arr[facet_id<T>::id].size = sizeof(T);\
}\

