files = juno/entity.cc juno/facet.cc juno/transform.cc main.cc juno/facet_id.cc juno/flow.cc juno/platform/sdl_window.cc
flags = -Wall -ggdb3 -std\=c++11 -Flibs -framework SDL2 -lm -rpath libs/
incl = -I include/glm -I libs/SDL2.framework/Headers -I include/imgui
build = build/build.out

target:
	g++ $(flags) $(files) $(incl) -o $(build) 