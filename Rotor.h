#ifndef ROTOR_H
#define ROTOR_H

#include <string>
#include <list>
#include "Scrambler.h"
#include "Mapping.h"

enum class RotorType;

struct RotorData {
    const RotorType type;
    Mapping map;
    const std::list<char> turnover;
};

class Rotor : public Scrambler {
public:
    Rotor(const RotorData& data) : rotorData(data), position('A'), ringSetting('A') {};
    Rotor(const RotorData& data, const char startposition, const char ringSetting)
    : rotorData(data), position(startposition), ringSetting(ringSetting) {};
    Rotor(const Rotor& rotor, const char startposition, const char ringSetting_)
    :   Rotor(rotor) {position = startposition; ringSetting = ringSetting_;};

    Rotor* clone() const { return new Rotor(*this); };

    char scramble(const char input);
    bool checkOnTurnover();
    void rotate();
    void setRingSetting(const char setting) {ringSetting = setting;};
    void setPosition(const char newPosition) {position = newPosition;};
    void setSettings(const char setting, const char newPosition) {position = newPosition; ringSetting = setting;};

private:
    RotorData rotorData;
    char position;
    char ringSetting;

    int calcPosition(const int offset);
};

#endif
