CFLAGS = -c -I$(HOME)/Programming/include
LFLAGS = -L$(HOME)/Programming/lib
LIBS = -ldataStructures

Project4: main.o output.o disjointSet.o Sampler.o
	g++ $(LFLAGS) -o Project4 main.o output.o disjointSet.o Sampler.o $(LIBS)

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

output.o: output.cpp
	g++ $(CFLAGS) -c output.cpp

disjointSet.o: disjointSet.cpp
	g++ $(CFLAGS) -c disjointSet.cpp

Sampler.o: Sampler.cpp
	g++  $(CFLAGS) -c Sampler.cpp

clean:
		rm Project4 main.o output.o disjointSet.o Sampler.o

