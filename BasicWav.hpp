#ifndef BASIC_SYNTHS_H
#define BASIC_SYNTHS_H
#include "Audio.hpp"

void fixDataLength(Audio* audioObject, double endTime);
void clearSound(Audio* audioObject, double startTime, double endTime);

void sinWav(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset = 0.0);
void squareWav(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset = 0.0);
void triangleWav(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset = 0.0);
void sawWav(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset = 0.0);
void pulseWav(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double percentOn, double offset = 0.0);

void sinAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset = 0.0);
void squareAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset = 0.0);
void triangleAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset = 0.0);
void sawAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset = 0.0);
void pulseAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double percentOn, double offset = 0.0);
void linearPulseAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double percentUp, double percentOn, double percentDown, double offset = 0.0);
void sinPulseAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double percentUp, double percentOn, double percentDown, double offset = 0.0);

#endif