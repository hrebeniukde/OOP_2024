#include "instrument.h"

Instrument::Instrument(std::string name, int manufactureYear)
{
    this->name = name;
    this->manufactureYear = manufactureYear;
}

std::string Instrument::getName() const
{
    return name;
}

void Instrument::setName(const std::string &newName)
{
    name = newName;
}

int Instrument::getManufactureYear() const
{
    return manufactureYear;
}

void Instrument::setManufactureYear(int newManufactureYear)
{
    manufactureYear = newManufactureYear;
}
