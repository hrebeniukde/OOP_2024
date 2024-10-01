#ifndef VOCALIST_H
#define VOCALIST_H

#include "musician.h"

class Vocalist : public Musician
{
public:
    Vocalist(std::string name, Instrument instrument, std::string voiceType);

    std::string getVoiceType() const;
    void setVoiceType(const std::string &newVoiceType);

private:
    std::string voiceType; // soprano/tenor
};

#endif // VOCALIST_H
