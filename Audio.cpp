#include "Audio.hpp"

Audio::Audio() : marker("RIFF"), type("WAVE"), format("fmt "), dataChunkHeader("data"){
	fileSize = 0;
	formatDataLength = 16;
	typeOfFormat = 1;
	numChannels = 1;
	sampleRate = 44100;
	bytesPerSec = 88200;
	bytesPerSample = 2;
	bitsPerSample = 16;
	dataSize = 0;
}

void Audio::generateWAV(string fileName){
	ofstream myFile;
	myFile.open(fileName, ios::out | ios::binary);

	fileSize = data.size() * 2 + 36;
	dataSize = data.size() * 2;

	myFile.write(marker, 4);
	myFile.write((char*)&fileSize, 4);
	myFile.write(type, 4);
	myFile.write(format, 4);
	myFile.write((char*)&formatDataLength, 4);
	myFile.write((char*)&typeOfFormat, 2);
	myFile.write((char*)&numChannels, 2);
	myFile.write((char*)&sampleRate, 4);
	myFile.write((char*)&bytesPerSec, 4);
	myFile.write((char*)&bytesPerSample, 2);
	myFile.write((char*)&bitsPerSample, 2);
	myFile.write(dataChunkHeader, 4);
	myFile.write((char*)&dataSize, 4);
	myFile.write((char*)&(data[0]), data.size() * 2);


	myFile.close();
}