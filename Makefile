CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g -O3
LIB = 
DEPS = Board.hpp
OBJECTS = $(DEPS:.hpp=.o)
PROGRAM = Chess

.PHONY: all clean lint

all: $(PROGRAM)

# Wildcard recipe to make .o files from corresponding .cpp file
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROGRAM)