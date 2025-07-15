

HEADERS=$(wildcard DSAproject/*.h)
SOURCES=$(wildcard DSAproject/*.cpp)

all: DSAproject

Debug: ${SOURCES}
	@ mkdir -p $@
	@ g++ -g ${^} -o $@/DSAproject

.phony: all
