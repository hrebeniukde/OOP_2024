#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>

class Instrument
{
public:
    Instrument(std::string name, int manufactureYear);

    std::string getName() const;
    void setName(const std::string &newName);

    int getManufactureYear() const;
    void setManufactureYear(int newManufactureYear);

private:
    std::string name;
    int manufactureYear;

};

#endif // INSTRUMENT_H
