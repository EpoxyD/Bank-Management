SOURCES=$(wildcard DSAproject/*.cpp)

all: Release

Debug: ${SOURCES}
	@ mkdir -p $@
	@ g++ -g ${^} -o $@/DSAproject

Release: ${SOURCES}
	@ mkdir -p $@
	@ g++ -O3 ${^} -o $@/DSAproject

.phony: Debug Release
