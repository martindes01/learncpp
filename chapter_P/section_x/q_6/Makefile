SHELL = /bin/sh

CXXFLAGS = -std=c++17

sources := $(wildcard *.cpp)
objects := $(sources:.cpp=.o)
binary = main

.PHONY: all clean

all: $(binary)

$(binary): $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(objects): %.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(binary) $(objects)
