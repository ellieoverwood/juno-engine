#pragma once
#include <stddef.h>

namespace util {
	template <typename T>
	struct maybe {
		T    val;
		bool is;

		maybe();
		maybe(T val);
	};
}
