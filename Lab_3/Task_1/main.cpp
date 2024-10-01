#include <iostream>
#include <vector>

#include "musicband.h"
#include "musician.h"
#include "vocalist.h"

using namespace std;

int main()
{
    Instrument guitar("Guitar", 1999);
    Instrument drum("Drum", 2004);
    Instrument piano("Piano", 2017);
    Instrument microphone("Microphone", 2024);

    std::string musicBandName;
    std::cout << "Enter the name of the music band: ";
    std::getline(std::cin, musicBandName);

    std::string musicBandStyle;
    std::cout << "Enter the style of the music band: ";
    std::getline(std::cin, musicBandStyle);

    std::string managerName;
    std::cout << "Enter the name of the music band leader: ";
    std::getline(std::cin, managerName);

    int musiciansCount = 0;
    std::cout << "Enter the number of musicians in the band: ";
    std::cin >> musiciansCount;
    std::cin.ignore();

    MusicBand musicBand(musicBandName, musicBandStyle, Manager(managerName));

    std::vector<Musician *> musicians;
    for (int index = 0; index < musiciansCount; index++) {
        std::string musicianName;
        std::cout << "Enter the name of musician #" << index + 1 << ": ";
        std::getline(std::cin, musicianName);

        std::string musicianInstrumentName;
        std::cout << "Enter the name of the musician's instrument (guitar, drum or piano): ";
        std::getline(std::cin, musicianInstrumentName);

        Instrument *musicianInstrument = nullptr;
        if (musicianInstrumentName == "guitar")
            musicianInstrument = &guitar;
        else if (musicianInstrumentName == "drum")
            musicianInstrument = &drum;
        else if (musicianInstrumentName == "piano")
            musicianInstrument = &piano;
        else {
            std::cout << "You didn't specify an instrument for the musician." << std::endl;
            return 1;
        }

        musicians.push_back(new Musician(musicianName, *musicianInstrument));
        musicBand.addMusician(musicians.back());
    }

    std::cout << std::endl;
    std::cout << "========== About band ==========" << std::endl;
    std::cout << "Band name: " << musicBand.getName() << std::endl;
    std::cout << "Band style: " << musicBand.getMusicStyle() << std::endl;
    std::cout << "Band leader: " << musicBand.getManager().getName() << std::endl;

    std::cout << "Musicians:" << std::endl;
    for (const Musician* musician : musicBand.getMusicians()) {
        std::cout << "- " << musician->getName() << " (" << musician->getInstrument().getName() << ")" << std::endl;
    }

    std::cout << std::endl;

    char addVocalist;
    std::cout << "Do you want to add a vocalist? (y/n): ";
    std::cin >> addVocalist;
    std::cin.ignore();

    if (addVocalist == 'y' || addVocalist == 'Y') {
        std::string vocalistName;
        std::cout << "Enter vocalist's name: ";
        std::getline(std::cin, vocalistName);

        std::string vocalistVoiceType;
        std::cout << "Enter vocalist's voice type (e.g., tenor, soprano): ";
        std::getline(std::cin, vocalistVoiceType);

        Vocalist newVocalist(vocalistName, microphone, vocalistVoiceType);
        std::cout << "Great! New vocalist " << newVocalist.getName() << "'s voice type: " << newVocalist.getVoiceType() << std::endl;
    }

    return 0;
}
