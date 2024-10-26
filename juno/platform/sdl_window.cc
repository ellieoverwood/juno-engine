#include "sdl_window.h"

#include <SDL.h>
#include <SDL_opengl.h>

SDL_Window* native_window;
SDL_GLContext sdl_context;

namespace juno::platform {
    void sdl_window::create(
        char* window_title, 
        int window_width, 
        int window_height, 
        int window_min_width, 
        int window_min_height,
        int opengl_version_major,
        int opengl_version_minor
    ) {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, opengl_version_major);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, opengl_version_minor);
        native_window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        SDL_SetWindowMinimumSize(native_window, window_min_width, window_min_height);
        sdl_context = SDL_GL_CreateContext(native_window);
        SDL_GL_SetSwapInterval(1);
    }

    void sdl_window::poll() {
        SDL_PumpEvents();
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_QUIT: to_terminate = true; break;
            }
        }
    }

    void sdl_window::swap() {
        SDL_GL_SwapWindow(native_window);
    }

    void sdl_window::terminate() {
        SDL_GL_DeleteContext(sdl_context);
        SDL_DestroyWindow(native_window);
        SDL_Quit();
    }
}