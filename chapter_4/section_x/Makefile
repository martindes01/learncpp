SHELL = /bin/sh

CXXFLAGS = -std=c++17

objects = q_4.o physics.o
binaries = q_3 q_4

.PHONY: all clean

all: $(binaries)

q_3: q_3.cpp
q_4: $(objects)

$(binaries):
	$(CXX) $(CXXFLAGS) $^ -o $@

$(objects): %.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(binaries) $(objects)
