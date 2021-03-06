#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <string>
#include "Scrambler.h"
#include "Mapping.h"

class Plugboard : public Scrambler {
public:
    Plugboard(std::string pairString);
    char scramble(const char input);
    Plugboard* clone() const { return new Plugboard(*this); };
private:
    Mapping map;
};

#endif
