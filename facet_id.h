#pragma once
#include "standard.h"

/*template <typename T>
struct facet_metadata {
}*/  // TODO: figure out

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
T* facet_id<T>::registry = __registry;
