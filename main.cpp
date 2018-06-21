#include "Audio.hpp"
#include "BasicSynths.hpp"

int main(){
	Audio audioObject = Audio();
	sinSound(&audioObject, 0.0, 2.0, 128.0, 32000);
	audioObject.generateWAV("SavedSynths/firstPhatSynth.wav");

	return 0;
}