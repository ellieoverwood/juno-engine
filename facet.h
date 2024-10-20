#pragma once

#include "standard.h"
#include "config.h"
#include "entity.h"

struct facet {
	template <typename T>
	static void declare();

	virtual void init     (entity self) {};
	virtual void update   (entity self) {};
	virtual void render   (entity self) {};
	virtual void tick     (entity self) {};
	virtual void destroy  (entity self) {};
};
