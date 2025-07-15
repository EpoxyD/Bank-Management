
HEADERS=$(wildcard DSAproject/*.h)
SOURCES=$(wildcard DSAproject/*.cpp)

all: Release

Debug: ${HEADERS} ${SOURCES}
	@ mkdir -p $@
	@ g++ -g ${^} -o $@/DSAproject

Release: ${HEADERS} ${SOURCES}
	@ mkdir -p $@
	@ g++ -O3 ${^} -o $@/DSAproject

.phony: Debug Release
