#ifndef AUDIO_H
#define AUDIO_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

class Audio{
public:
	char marker[5];
	int fileSize;
	char type[5];
	char format[5];
	int formatDataLength;
	short typeOfFormat;
	short numChannels;
	int sampleRate;
	int bytesPerSec;
	short bytesPerSample;
	short bitsPerSample;
	char dataChunkHeader[5];
	int dataSize;

	vector<double> data;

	Audio();
	void generateWAV(string fileName, int loudMultiplier);
};

#endif