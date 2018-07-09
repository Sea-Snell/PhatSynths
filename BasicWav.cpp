#include "BasicWav.hpp"

void fixDataLength(Audio* audioObject, double endTime){
	int newLength = endTime * audioObject->sampleRate;
	if (newLength > audioObject->data.size()){
		audioObject->data.resize(newLength, 0);
	}
}

void clearSound(Audio* audioObject, double startTime, double endTime){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		audioObject->data[i] = 0.0;
	}
}




void sinWav(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		audioObject->data[i] += volume * sin(2.0 * M_PI * frequency * t + offset);
	}
}

void squareWav(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		if (sin(2.0 * M_PI * frequency * t + offset) > 0.0){
			audioObject->data[i] += volume;
		}
		else{
			audioObject->data[i] += -volume;
		}
	}
}

void triangleWav(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		audioObject->data[i] += volume * ((2.0 * asin(sin(2.0 * M_PI * frequency * t + offset))) / M_PI);
	}
}

void sawWav(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		audioObject->data[i] += volume * ((fmod(2.0 * M_PI * frequency * t + offset, 2.0 * M_PI) / (M_PI)) - 1.0);
	}
}

void pulseWav(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double percentOn, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		double pos = fmod(2.0 * M_PI * frequency * t + offset, 2.0 * M_PI) / (2.0 * M_PI);
		if (pos < percentOn){
			audioObject->data[i] += volume;
		}
	}
}




void sinAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		audioObject->data[i] *= volume * sin(2.0 * M_PI * frequency * t + offset);
	}
}

void squareAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		if (sin(2.0 * M_PI * frequency * t + offset) > 0.0){
			audioObject->data[i] *= volume;
		}
		else{
			audioObject->data[i] *= -volume;
		}
	}
}

void triangleAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		audioObject->data[i] *= volume * ((2.0 * asin(sin(2.0 * M_PI * frequency * t + offset))) / M_PI);
	}
}

void sawAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		audioObject->data[i] *= volume * ((fmod(2.0 * M_PI * frequency * t + offset, 2.0 * M_PI) / (M_PI)) - 1.0);
	}
}

void pulseAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double percentOn, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		double pos = fmod(2.0 * M_PI * frequency * t + offset, 2.0 * M_PI) / (2.0 * M_PI);
		if (pos < percentOn){
			audioObject->data[i] *= volume;
		}
		else{
			audioObject->data[i] *= 0.0;
		}
	}
}

void linearPulseAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double percentUp, double percentOn, double percentDown, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		double pos = fmod(2.0 * M_PI * frequency * t + offset, 2.0 * M_PI) / (2.0 * M_PI);
		if (pos < percentUp){
			audioObject->data[i] *= volume * (pos / percentUp);
		}
		else if (pos < percentUp + percentOn){
			audioObject->data[i] *= volume;
		}
		else if (pos < percentUp + percentOn + percentDown){
			audioObject->data[i] *= volume * (((percentUp + percentOn + percentDown) - pos) / percentDown);
		}
		else{
			audioObject->data[i] *= 0.0;
		}
	}
}

void sinPulseAmp(Audio* audioObject, double startTime, double endTime, double frequency, double volume, double percentUp, double percentOn, double percentDown, double offset){
	fixDataLength(audioObject, endTime);
	for (int i = startTime * audioObject->sampleRate; i < endTime * audioObject->sampleRate; i++){
		double t = (double)(i) / (double)(audioObject->sampleRate);
		double pos = fmod(2.0 * M_PI * frequency * t + offset, 2.0 * M_PI) / (2.0 * M_PI);
		if (pos < percentUp){
			audioObject->data[i] *= volume * ((1.0 - cos((pos / percentUp) * M_PI)) * 0.5);
		}
		else if (pos < percentUp + percentOn){
			audioObject->data[i] *= volume;
		}
		else if (pos < percentUp + percentOn + percentDown){
			audioObject->data[i] *= volume * (0.5 * (1.0 + cos(((pos - (percentUp + percentOn)) / percentDown) * M_PI)));
		}
		else{
			audioObject->data[i] *= 0.0;
		}
	}
}




