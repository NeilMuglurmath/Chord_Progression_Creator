#include "Chord.h"
#include <map>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;

class Execute
{
private:
public:
    const int PATTERN_END = 33;
    const vector<double> WEIGHTS = {0, 4, 2, 3, 2, 3.5, 3, 2};
    const double TOTAL_WEIGHT = 19.5;
    int main_current_pos = 1;

    void generate_chords()
    {
        while (PATTERN_END > current_pos)
        {
            int test = rand();
            double rand_num = fmod(test, TOTAL_WEIGHT);                  // generate chord
            double length = fmod(rand(), (PATTERN_END - current_pos + 1)); // random length that fits in pattern
            current_pos += length;

            Chord chord;

            if (rand_num < WEIGHTS.at(1))
            {
                chord = {length, 1, {}};
            }
            else if (rand_num < WEIGHTS.at(2) + WEIGHTS.at(1))
            {
                chord = {length, 2, {}};
            }
            else if (rand_num < WEIGHTS.at(3) + WEIGHTS.at(2) + WEIGHTS.at(1))
            {
                chord = {length, 3, {}};
            }
            else if (rand_num < WEIGHTS.at(4) + WEIGHTS.at(3) + WEIGHTS.at(2) + WEIGHTS.at(1))
            {
                chord = {length, 4, {}};
            }
            else if (rand_num < WEIGHTS.at(5) + WEIGHTS.at(4) + WEIGHTS.at(3) + WEIGHTS.at(2) + WEIGHTS.at(1))
            {
                chord = {length, 5, {}};
            }
            else if (rand_num < WEIGHTS.at(6) + WEIGHTS.at(5) + WEIGHTS.at(4) + WEIGHTS.at(3) + WEIGHTS.at(2) + WEIGHTS.at(1))
            {
                chord = {length, 6, {}};
            }
            else
            {
                chord = {length, 7, {}};
            }
            chord.print_chord(cout);
        }
    }
};

int main(int argc, char const *argv[])
{
    Execute e;
    srand(static_cast<unsigned int>(time(0)));
    e.generate_chords();
    return 0;
}
