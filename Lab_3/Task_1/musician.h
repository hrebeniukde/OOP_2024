#ifndef MUSICIAN_H
#define MUSICIAN_H

#include <string>

#include "instrument.h"

class Musician
{
public:
    Musician(std::string name, Instrument instrument);

    std::string getName() const;
    void setName(const std::string &newName);

    Instrument getInstrument() const;
    void setInstrument(const Instrument &newInstrument);

private:
    std::string name;
    Instrument instrument;

};

#endif // MUSICIAN_H
