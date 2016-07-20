CC=g++
CFLAGS=-c -Wall -I/mingw64/include -g -std=c++14 -Wall
LDFLAGS=-L/mingw64/lib -lopengl32 -lglew32 -lglfw3
SOURCES=src/main.cpp src/window.cpp src/mesh.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC)  $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm src/*.o hello.exe