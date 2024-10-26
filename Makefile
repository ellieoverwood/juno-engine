files = juno/entity.cc juno/facet.cc juno/transform.cc main.cc juno/facet_id.cc juno/flow.cc juno/platform/sdl_window.cc juno/debug/dev_menu.cc
flags = -Wall -ggdb3 -std\=c++11 -Flibs -framework SDL2 -lm -rpath libs/ -DGL_GLEXT_PROTOTYPES
imgui_files = include/imgui/imgui.cpp include/imgui/imgui_demo.cpp include/imgui/imgui_draw.cpp include/imgui/imgui_tables.cpp include/imgui/imgui_widgets.cpp include/imgui/backends/imgui_impl_sdl2.cpp include/imgui/backends/imgui_impl_opengl3.cpp
incl = -I include/glm -I libs/SDL2.framework/Headers -I include/imgui -I include/imgui/backends
build = build/build.out

target:
	g++ $(flags) $(files) $(imgui_files) $(incl) -o $(build) 