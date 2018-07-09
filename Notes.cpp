#include "Notes.hpp"
#include <map>

double getNote(string note, int octave){
	map<string, double> notes;

	notes["C"] = 261.63;
	notes["C#"] = 277.18;
	notes["Db"] = 277.18;
	notes["D"] = 293.66;
	notes["D#"] = 311.13;
	notes["Eb"] = 311.13;
	notes["E"] = 329.63;
	notes["F"] = 349.23;
	notes["F#"] = 369.99;
	notes["Gb"] = 369.99;
	notes["G"] = 392.00;
	notes["G#"] = 415.30;
	notes["Ab"] = 415.30;
	notes["A"] = 440.00;
	notes["A#"] = 466.16;
	notes["Bb"] = 466.16;
	notes["B"] = 493.88;

	return notes[note] * pow(2.0, (double)(octave) - 4.0);
}