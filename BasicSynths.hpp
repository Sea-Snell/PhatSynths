#ifndef BASIC_SYNTHS_H
#define BASIC_SYNTHS_H
#include "Audio.hpp"

void fixDataLength(Audio* audioObject, double endTime);

void zeroSound(Audio* audioObject, double startTime, double endTime);
void sinSound(Audio* audioObject, double startTime, double endTime, double frequency, int volume, double offset = 0.0);

#endif