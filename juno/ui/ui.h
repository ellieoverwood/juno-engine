#pragma once
#include "../entity.h"
#include <imgui.h>
#include "../platform/wrapper.h"

#define __DEBUG_LOG_TEMPLATE(has_color, r, g, b, title, fmt, ...) \
do {\
    juno::ui::logf(has_color, ImVec4(r, g, b, 1.0), "[" title "](%0.2f) %s:%d: " fmt,\
        ((float)juno::wrapper::ticks()/1000.0),\
        __FILE__,\
        __LINE__,\
        ##__VA_ARGS__\
    );\
} while (0);\

#define DEBUG_LOG(fmt, ...)  __DEBUG_LOG_TEMPLATE(false, 0, 0, 0,   "log",     fmt, ##__VA_ARGS__)
#define DEBUG_WARN(fmt, ...) __DEBUG_LOG_TEMPLATE(true,  1, 1, 0,   "warning", fmt, ##__VA_ARGS__)
#define DEBUG_ERR(fmt, ...)  __DEBUG_LOG_TEMPLATE(true,  1, 0, 0,   "error",   fmt, ##__VA_ARGS__)
#define DEBUG_POINT          __DEBUG_LOG_TEMPLATE(true,  0.5, 0.8, 1, "trigger", "", 0)

namespace juno {
    namespace ui {
        void update();
        void inspect(entity e);
        void log(char* text, bool has_color, ImVec4 color);
        void logf(bool has_color, ImVec4 color, char* fmt, ...);
    }
}