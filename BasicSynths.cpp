#include "BasicSynths.hpp"

void fixDataLength(Audio* audioObject, double endTime){
	int newLength = endTime * audioObject->sampleRate;
	if (newLength > audioObject->data.size()){
		audioObject->data.resize(newLength, 0);
	}
}

void zeroSound(Audio* audioObject, double startTime, double endTime){
	fixDataLength(audioObject, endTime);

	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		audioObject->data[i] = 0;
	}
}

void sinSound(Audio* audioObject, double startTime, double endTime, double frequency, int volume, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		audioObject->data[i] = volume * sin(2.0 * M_PI * frequency * t + offset);
	}
}