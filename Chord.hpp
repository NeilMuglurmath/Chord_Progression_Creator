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

class Chord
{
private:
    int length; // length in 1/8th notes
    int num;
    std::map<int, std::string> mods;

public:
    Chord(int length_in, int num_in, std::map<int, std::string> &mods_in);
    void print_chord(std::ostream &os);
    ~Chord();
};

#endif