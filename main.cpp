#include "Chord.h"
#include <map>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class Execute
{
private:
public:
    void test_chord_print()
    {
    }
};

int main(int argc, char const *argv[])
{
    current_pos = 1;
    Chord c(10, 10, {});
    c.print_chord(cout);
    return 0;
}
