files = juno/entity.cc juno/facet.cc juno/transform.cc main.cc juno/facet_id.cc juno/flow.cc
flags = -Wall -Wpedantic -g
build = build/build.out

target:
	g++ $(flags) $(files) -o $(build) -I libs/glm -I libs/SDL2 -I libs/imgui
