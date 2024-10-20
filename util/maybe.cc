#include "maybe.h"

template <typename T>
util::maybe<T>::maybe() {
	val = NULL;
	is  = false;
}

template <typename T>
util::maybe<T>::maybe(T __val) {
	val = __val;
	is  = true;
}
