SHELL = /bin/sh

CXXFLAGS = -std=c++17

sources := $(wildcard *.cpp)
binaries := $(sources:.cpp=)

.PHONY: all clean

all: $(binaries)

$(binaries): %: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(binaries)
