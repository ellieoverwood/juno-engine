#include "sdl_window.h"
#include "../ui/ui.h"

#include <SDL.h>
#include <SDL_opengl.h>

#include <imgui.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_opengl3.h>
#include <imgui_internal.h>       // Required for docking-specific functions like DockSpace

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

        native_window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        SDL_SetWindowMinimumSize(native_window, window_min_width, window_min_height);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, opengl_version_major);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, opengl_version_minor);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,4);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        // enable double buffering (should be on by default)
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        /*#ifdef __APPLE__       
        //SDL_GL_SetAttribute(SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG, true);
        //SDL_SetHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #endif*/

        sdl_context = SDL_GL_CreateContext(native_window);
        SDL_GL_MakeCurrent(native_window, sdl_context);
        SDL_GL_SetSwapInterval(1);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        // Setup Platform/Renderer backends
        ImGui_ImplSDL2_InitForOpenGL(native_window, sdl_context);
        ImGui_ImplOpenGL3_Init("#version 330");
    }

    void sdl_window::poll() {
        SDL_PumpEvents();
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_QUIT: to_terminate = true; break;
            }
            ImGui_ImplSDL2_ProcessEvent(&event);
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }

    void sdl_window::swap() {
        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        SDL_GL_SwapWindow(native_window);
    }

    void sdl_window::terminate() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();

        SDL_GL_DeleteContext(sdl_context);
        SDL_DestroyWindow(native_window);
        SDL_Quit();
    }
}