LIBS = -lGL -lGLEW -lglfw
CFLAGS = -o build/run
SRC = $(wildcard ./src/*.cpp)

all:
	mkdir -p build
	g++ $(SRC) $(CFLAGS) $(LIBS)

run: all
	./build/run
