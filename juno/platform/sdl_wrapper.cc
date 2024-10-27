#include "wrapper.h"
#include <SDL.h>

namespace juno::wrapper {
    uint32_t ticks() {
        return SDL_GetTicks();
    }
}