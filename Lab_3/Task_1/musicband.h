#ifndef MUSICBAND_H
#define MUSICBAND_H

#include <string>
#include <vector>

#include "musician.h"
#include "manager.h"

class MusicBand
{
public:
    MusicBand(std::string name, std::string musicStyle, Manager manager);

    std::string getName() const;
    void setName(const std::string &newName);

    std::string getMusicStyle() const;
    void setMusicStyle(const std::string &newMusicStyle);

    std::vector<Musician *> getMusicians() const;
    void setMusicians(const std::vector<Musician *> &newMusicians);

    Manager getManager() const;
    void setManager(const Manager &newManager);

    void addMusician(Musician* musician);
    void removeMusician(Musician* musician);

private:
    std::string name;
    std::string musicStyle;
    std::vector<Musician*> musicians;
    Manager manager;

};

#endif // MUSICBAND_H
