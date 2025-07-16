DATABASES=$(wildcard DSAproject/*.txt)
HEADERS=$(wildcard DSAproject/*.h)
SOURCES=$(wildcard DSAproject/*.cpp)

all: Release

Debug: ${HEADERS} ${SOURCES} ${DATABASES}
	@ rm -rf ${DATABASES}
	@ mkdir -p $@
	@ g++ -g ${^} -o $@/DSAproject

Release: ${HEADERS} ${SOURCES} ${DATABASES}
	@ rm -rf ${DATABASES}
	@ mkdir -p $@
	@ g++ -O3 ${^} -o $@/DSAproject

.phony: Debug Release
