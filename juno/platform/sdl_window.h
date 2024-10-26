#pragma once
#include "../window.h"

namespace juno {
    namespace platform {
        struct sdl_window : public window {
            sdl_window() {};

            void create(
                char* window_title, 
                int window_width, 
                int window_height, 
                int window_min_width, 
                int window_min_height,
                int opengl_version_major,
                int opengl_version_minor
            ) override;

            void poll() override;
            void swap() override;
            void terminate() override;
        };
    }
}