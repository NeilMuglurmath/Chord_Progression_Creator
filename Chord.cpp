#include "Chord.h"
#include <map>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

Chord::Chord(double length_in, int num_in, std::map<int, std::string> &mods_in)
    : length(length_in), num(num_in), mods(mods_in)
{
}

Chord::Chord() : length(3), num(1), mods({})
{
}

void Chord::print_chord(std::ostream &os)
{
    os << num << " ";
    current_pos += 0.5;
    for (double i = 0.5; i < length; i += 0.5)
    {
        if (floor(current_pos) == current_pos)
        {
            os << "|";
        }
        os << "_ ";
        current_pos += 0.5;
    }
}