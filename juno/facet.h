#pragma once

#include "standard.h"
#include "entity.h"

namespace juno {
struct facet {
	template <typename T>
	static void declare();

	virtual void init     (entity self) {};
	virtual void update   (entity self) {};
	virtual void render   (entity self) {};
	virtual void tick     (entity self) {};
	virtual void destroy  (entity self) {};
	virtual void ui       (entity self) {};
};
}
