CC = g++
CFLAGS  = -g -Wall -O2 -std=c++11
OBJECTS = Audio.o BasicWav.o Notes.o main.o

all: PhatSynths

PhatSynths: $(OBJECTS)
	$(CC) $(CFLAGS) -o PhatSynths $(OBJECTS)

Audio.o: Audio.cpp Audio.hpp
	$(CC) $(CFLAGS) -c Audio.cpp

BasicWav.o: BasicWav.cpp BasicWav.hpp Audio.hpp
	$(CC) $(CFLAGS) -c BasicWav.cpp

Notes.o: Notes.cpp Notes.hpp Audio.hpp
	$(CC) $(CFLAGS) -c Notes.cpp

main.o: main.cpp Audio.hpp BasicWav.hpp Notes.hpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) PhatSynths $(OBJECTS)