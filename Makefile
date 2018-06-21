CC = g++
CFLAGS  = -g -Wall -O2 -std=c++11
OBJECTS = Audio.o BasicSynths.o main.o

all: PhatSynths

PhatSynths: $(OBJECTS)
	$(CC) $(CFLAGS) -o PhatSynths $(OBJECTS)

Audio.o: Audio.cpp Audio.hpp
	$(CC) $(CFLAGS) -c Audio.cpp

BasicSynths.o: BasicSynths.cpp BasicSynths.hpp Audio.hpp
	$(CC) $(CFLAGS) -c BasicSynths.cpp

main.o: main.cpp Audio.hpp BasicSynths.hpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) PhatSynths $(OBJECTS)