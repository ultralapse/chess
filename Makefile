CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g -O3
LIB = -lboost_unit_test_framework
DEPS = Game.hpp Board.hpp
PIECES_SRC = $(wildcard pieces/*.cpp)
PIECES_OBJ = $(PIECES_SRC:pieces/%.cpp=%.o)
OBJECTS = $(DEPS:.hpp=.o) $(PIECES_OBJ)
PROGRAM = Chess

.PHONY: all clean lint

all: $(PROGRAM) test

# Wildcard recipe to make .o files from corresponding .cpp file
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

# Wildcard recipe to make .o files from corresponding .cpp file in pieces/
%.o: pieces/%.cpp
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

test: test.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROGRAM) test

lint:
	cpplint *.hpp *.cpp

