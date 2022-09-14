CXX = clang++
CXXFLAGS = -Wall

all: inheritance

inheritance: inheritance.o tuple.o
	$(CXX) $(CXXFLAGS) inheritance.o tuple.o -o inheritance

inheritance.o tuple.o: tuple.h

.PHONY: clean
clean:
	-rm inheritance *.o
