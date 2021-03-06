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
    const int MOD_WEIGHT = 3;
    const int MOD_CUTOFF = 1;

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

        int chord_num = 1;

        for (size_t i = 0; i < num_progressions; ++i)
        {
            current_pos = 1;
            main_current_pos = 1;
            chord_num = 1;
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
                int mod_rand_num = rand() % MOD_WEIGHT;

                if (chord_num < 4)
                {
                    length = floor(length / 3); // force shorter first 2 chords
                }

                if (chord_num == 1)
                {
                    rand_num = 1; // force first chord to be root
                }

                Chord chord;

                vector<int> mods;

                if (rand_num < WEIGHTS.at(1))
                {
                    if (mod_rand_num <= MOD_CUTOFF)
                    {
                        mods.push_back(7);
                        mods.push_back(9);
                    }
                    chord = {length, 1, mods};
                }
                else if (rand_num < WEIGHTS.at(2) + WEIGHTS.at(1))
                {
                    if (mod_rand_num <= MOD_CUTOFF)
                    {
                        mods.push_back(5);
                    }
                    chord = {length, 2, mods};
                }
                else if (rand_num < WEIGHTS.at(3) + WEIGHTS.at(2) + WEIGHTS.at(1))
                {
                    if (mod_rand_num <= MOD_CUTOFF)
                    {
                        mods.push_back(2);
                    }
                    chord = {length, 3, mods};
                }
                else if (rand_num < WEIGHTS.at(4) + WEIGHTS.at(3) + WEIGHTS.at(2) + WEIGHTS.at(1))
                {
                    if (mod_rand_num <= MOD_CUTOFF)
                    {
                        mods.push_back(2);
                    }
                    chord = {length, 4, mods};
                }
                else if (rand_num < WEIGHTS.at(5) + WEIGHTS.at(4) + WEIGHTS.at(3) + WEIGHTS.at(2) + WEIGHTS.at(1))
                {
                    if (mod_rand_num <= MOD_CUTOFF)
                    {
                        mods.push_back(4);
                    }
                    chord = {length, 5, mods};
                }
                else if (rand_num < WEIGHTS.at(6) + WEIGHTS.at(5) + WEIGHTS.at(4) + WEIGHTS.at(3) + WEIGHTS.at(2) + WEIGHTS.at(1))
                {
                    if (mod_rand_num <= MOD_CUTOFF)
                    {
                        mods.push_back(7);
                    }
                    chord = {length, 6, mods};
                }
                else
                {
                    if (mod_rand_num <= MOD_CUTOFF)
                    {
                        mods.push_back(3);
                    }
                    chord = {length, 7, mods};
                }
                chord.print_chord(fout, pattern_end, current_pos);
                ++chord_num;
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
