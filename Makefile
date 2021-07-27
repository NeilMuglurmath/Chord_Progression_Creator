CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic --std=c++11 -g

all: execute.exe

execute.exe: Chord.cpp execute.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.SUFFIXES:

.PHONY: clean
clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump

