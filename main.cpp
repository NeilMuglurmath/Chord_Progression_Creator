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

    void generate_chord()
    {
        while (current_pos < PATTERN_END)
        {
            double rand_num = fmod(rand(), TOTAL_WEIGHT);      // generate chord
            int length = rand() % (PATTERN_END - current_pos); // random length that fits in pattern

            if (rand_num < WEIGHTS.at(1))
            {
                Chord chord(length, 1, {});
            }
            else if (rand_num < WEIGHTS.at(2))
            {
                Chord chord(length, 2, {});
            }
            else if (rand_num < WEIGHTS.at(3))
            {
                Chord chord(length, 3, {});
            }
            else if (rand_num < WEIGHTS.at(4))
            {
                Chord chord(length, 4, {});
            }
            else if (rand_num < WEIGHTS.at(5))
            {
                Chord chord(length, 5, {});
            }
            else if (rand_num < WEIGHTS.at(6))
            {
                Chord chord(length, 6, {});
            }
            else if (rand_num < WEIGHTS.at(7))
            {
                Chord chord(length, 7, {});
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    current_pos = 1;
    Chord c(10, 10, {});
    c.print_chord(cout);
    return 0;
}
