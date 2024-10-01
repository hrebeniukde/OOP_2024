#include "musicband.h"

#include <algorithm>
#include <iostream>

MusicBand::MusicBand(std::string name, std::string musicStyle, Manager manager) : manager(manager)
{
    this->name = name;
    this->musicStyle = musicStyle;
}

Manager MusicBand::getManager() const
{
    return manager;
}

void MusicBand::setManager(const Manager &newManager)
{
    manager = newManager;
}

std::vector<Musician *> MusicBand::getMusicians() const
{
    return musicians;
}

void MusicBand::setMusicians(const std::vector<Musician *> &newMusicians)
{
    musicians = newMusicians;
}

std::string MusicBand::getMusicStyle() const
{
    return musicStyle;
}

void MusicBand::setMusicStyle(const std::string &newMusicStyle)
{
    musicStyle = newMusicStyle;
}

std::string MusicBand::getName() const
{
    return name;
}

void MusicBand::setName(const std::string &newName)
{
    name = newName;
}

void MusicBand::addMusician(Musician *musician)
{
    musicians.push_back(musician);
}

void MusicBand::removeMusician(Musician *musician)
{
    auto elementPosition = std::find(musicians.begin(), musicians.end(), musician);
    if (elementPosition == musicians.end()) {
        std::cout << "No musician was found in the list" << std::endl;
        return;
    }

    musicians.erase(elementPosition);
}
