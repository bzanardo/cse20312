c4game: testmain.o c4board.o c4col.o
	g++ -o c4game testmain.o c4board.o c4col.o

testmain.o: testmain.cpp
	g++ -c testmain.cpp

c4col.o: c4col.cpp c4col.h
	g++ -c c4col.cpp

c4board.o: c4board.cpp c4board.h
	g++ -c c4board.cpp

clean:
	rm c4board *.o
