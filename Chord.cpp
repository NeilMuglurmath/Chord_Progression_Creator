#include "Chord.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

Chord::Chord(double length_in, int num_in, vector<int> mods_in)
    : length(length_in), num(num_in), mods(mods_in)
{
}

Chord::Chord() : length(1), num(1), mods({})
{
}

void Chord::print_chord(std::ostream &os, int pattern_end, double &current_pos)
{
    if (current_pos >= pattern_end)
    {
        os << "|| ";
        return;
    }
    if (fmod(current_pos - 1, 4) == 0)
    {
        os << "|| ";
    }
    else if (floor(current_pos) == current_pos)
    {
        os << "| ";
    }
    os << num << " {";

    for (size_t i = 0; i < mods.size(); ++i)
    {
        os << mods.at(i) << " ";
    }

    os << "}";

    current_pos += 0.5;
    for (double i = 0.5; i < length; i += 0.5)
    {
        if (current_pos >= pattern_end)
        {
            return;
        }
        if (fmod(current_pos - 1, 4) == 0)
        {
            os << "|| ";
        }
        else if (floor(current_pos) == current_pos)
        {
            os << "| ";
        }

        os << "_ ";
        current_pos += 0.5;
    }
}
