tvchar: charactermain.o himym.o got.o character.o
	g++ -std=c++14 -o tvchar charactermain.o himym.o got.o character.o

charactermain.o: charactermain.cpp
	g++ -std=c++14 -c charactermain.cpp

himym.o: himym.cpp himym.h
	g++ -std=c++14 -c himym.cpp

got.o: got.cpp got.h
	g++ -std=c++14 -c got.cpp

character.o: character.cpp character.h
	g++ -std=c++14 -c character.cpp
  
clean:
	rm character *.o
