CC=g++
CFLAGS=-c -Wall -I/mingw64/include -g -std=c++14 -Wall
LDFLAGS=-L/mingw64/lib -lopengl32 -lglew32 -lglfw3
SOURCES=main.cpp window.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC)  $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o