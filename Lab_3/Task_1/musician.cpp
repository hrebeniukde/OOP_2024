#include "musician.h"

Musician::Musician(std::string name, Instrument instrument) : instrument(instrument)
{
    this->name = name;
}

std::string Musician::getName() const
{
    return name;
}

void Musician::setName(const std::string &newName)
{
    name = newName;
}

Instrument Musician::getInstrument() const
{
    return instrument;
}

void Musician::setInstrument(const Instrument &newInstrument)
{
    instrument = newInstrument;
}
