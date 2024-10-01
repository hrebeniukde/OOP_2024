#include "vocalist.h"

Vocalist::Vocalist(std::string name, Instrument instrument, std::string voiceType)
    : Musician(name, instrument)
{
    this->voiceType = voiceType;
}

std::string Vocalist::getVoiceType() const
{
    return voiceType;
}

void Vocalist::setVoiceType(const std::string &newVoiceType)
{
    voiceType = newVoiceType;
}
