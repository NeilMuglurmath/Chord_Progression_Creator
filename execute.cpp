#include "Chord.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;

class Execute
{
private:
public:
    const vector<double> WEIGHTS = {0, 4, 2, 3, 2, 3.5, 3, 2};
    const double TOTAL_WEIGHT = 19.5;
    int main_current_pos = 1;
    string output_filename;
    int num_progressions;
    double current_pos;
    int pattern_end;

    bool areArgumentsGood(int argc, char const *argv[])
    {
        if (argc != 4)
        {
            return false;
        }
        return true;
    }

    void generate_chords(ofstream &fout)
    {
        for (size_t i = 0; i < num_progressions; ++i)
        {
            current_pos = 1;
            main_current_pos = 1;
            if (i != 0)
            {
                fout << "|| ";
                fout << endl
                     << endl;
            }
            while (pattern_end > current_pos)
            {
                int test = rand();
                double rand_num = fmod(test, TOTAL_WEIGHT);                    // generate chord
                double length = fmod(rand(), (pattern_end - current_pos + 1)); // random length that fits in pattern

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
                chord.print_chord(fout, pattern_end, current_pos);
            }
        }
        fout << "|| ";
        fout << endl
             << endl;
    }

    void read_in_arguments(int argc, char const *argv[])
    {
        output_filename = argv[1];
        pattern_end = 4 * stoi(argv[2]) + 1;
        num_progressions = stoi(argv[3]);
        current_pos = 1;
    }
};

int main(int argc, char const *argv[])
{
    Execute e;
    if (!e.areArgumentsGood(argc, argv))
    {
        cout << "Usage: execute.exe OUTPUT_FILENAME "
             << "PATTERN_LENGTH_IN_BARS "
             << "NUM_PROGRESSIONS "
             << endl;

        return 1;
    }

    e.read_in_arguments(argc, argv);

    ofstream fout;
    fout.open(e.output_filename);
    if (!fout.is_open())
    {
        cout << "Error opening file: " << e.output_filename << endl;
        return 1;
    }

    srand(static_cast<unsigned int>(time(0)));
    e.generate_chords(fout);
    return 0;
}
