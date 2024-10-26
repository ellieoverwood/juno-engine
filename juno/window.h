#pragma once
#include "standard.h"

namespace juno {
    struct window {
        window() {};

        virtual void create(
            char* window_title, 
            int window_width, 
            int window_height, 
            int window_min_width, 
            int window_min_height,
            int opengl_version_major,
            int opengl_version_minor
        ) {};
        virtual void poll() {};
        virtual void swap() {};
        virtual void terminate() {};
        
        bool to_terminate = false;
    };

    namespace state {
        extern juno::window* window;
    }
}