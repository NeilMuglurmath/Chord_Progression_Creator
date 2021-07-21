CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic --std=c++11 -g

all: test

test: Card_public_test.exe Card_tests.exe Pack_public_test.exe Pack_tests.exe \
		Player_public_test.exe Player_tests.exe \
		euchre.exe
	./Card_public_test.exe
	./Card_tests.exe

	./Pack_public_test.exe
	./Pack_tests.exe

	./Player_public_test.exe
	./Player_tests.exe

	./euchre.exe pack.in noshuffle 1 Adi Simple Barbara Simple Chi-Chih Simple Dabbala Simple > euchre_test00.out
	diff -q euchre_test00.out euchre_test00.out.correct
	./euchre.exe pack.in shuffle 10 Edsger Simple Fran Simple Gabriel Simple Herb Simple > euchre_test01.out
	diff -q euchre_test01.out euchre_test01.out.correct
	./euchre.exe pack.in noshuffle 3 Ivan Human Judea Human Kunle Human Liskov Human < euchre_test50.in > euchre_test50.out
	diff -q euchre_test50.out euchre_test50.out.correct


Card_public_test.exe: Card.cpp Card_public_test.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Card_tests.exe: Card.cpp Card_tests.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Pack_public_test.exe: Card.cpp Pack.cpp Pack_public_test.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Pack_tests.exe: Card.cpp Pack.cpp Pack_tests.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Player_public_test.exe: Card.cpp Player.cpp Player_public_test.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Player_tests.exe: Card.cpp Player.cpp Player_tests.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

main.exe: Chord.cpp main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.SUFFIXES:

.PHONY: clean
clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump

