#include "Chord.hpp"
#include <map>
#include <string>
#include <iostream>
using namespace std;

Chord::Chord(int length_in, int num_in, std::map<int, std::string> &mods_in)
    : length(length_in), num(num_in), mods(mods_in)
{
}

void Chord::print_chord(std::ostream &os)
{
    os << num << " ";
    for (size_t i = 0; i < length; ++i)
    {
        os << "_ ";
    }
}