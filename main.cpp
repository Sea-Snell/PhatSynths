#include "Audio.hpp"
#include "BasicWav.hpp"
#include "Notes.hpp"

int main(){
	Audio audioObject = Audio();

	// sinWav(&audioObject, 0.0, 10.0, 200.0, 0.4, 0.1);
	// sinWav(&audioObject, 0.0, 10.0, 57.5, 0.7, 0.1);
	// sinWav(&audioObject, 0.0, 10.0, 199.0, 0.4, 0.1);
	// sinWav(&audioObject, 0.0, 10.0, 56.75, 0.7, 0.1);
	// sinWav(&audioObject, 0.0, 10.0, 189.0, 0.4, 0.1);
	// sinWav(&audioObject, 0.0, 10.0, 54.25, 0.7, 0.1);
	// sinPulseAmp(&audioObject, 0.0, 10.0, 0.25, 1.0, 0.4, 0.0, 0.3);

	triangleWav(&audioObject, 0.0, 10.0, 74.0, 1.0);
	triangleWav(&audioObject, 0.0, 10.0, 75.0, 1.0);
	triangleWav(&audioObject, 0.0, 10.0, 70.0, 0.4);
	linearPulseAmp(&audioObject, 0.0, 10.0, 6.0, 1.0, 0.4, 0.0, 0.3);

	audioObject.generateWAV("SavedSynths/eigthPhatSynth.wav", 10000);

	return 0;
}