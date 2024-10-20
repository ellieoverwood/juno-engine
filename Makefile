files = entity.cc facet.cc util/maybe.cc transform.cc main.cc
flags = -Wall -Wpedantic -g
build = build/build.out

target:
	g++ $(flags) $(files) -o $(build)
