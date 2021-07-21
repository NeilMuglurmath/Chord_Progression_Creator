#ifndef CHORD_H_
#define PACK_H_

/* Chord.h
 *
 * Represents a chord relative to the root note of a scale
 *
 * by Neil Muglurmath <neil.muglurmath@gmail.com>
 * Jul. 21, 2021
 */

#include <map>
#include <string>
#include <iostream>

static double current_pos;

class Chord
{
private:
    double length; // length in 1/4th notes
    int num;

    std::map<int, std::string> mods;

public:
    Chord(double length_in, int num_in, std::map<int, std::string> &mods_in);
    Chord();
    void print_chord(std::ostream &os);
};

#endif