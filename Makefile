

CXX=clang++-5.0 
CXXFLAGS=-std=c++17


all:Board.o BoardRow.o Content.o Content.o IllegalCoordinateException.o Player.o Coordinate.o Champion.o TicTacToe.o DummyPlayers.o main.o 

Board.o:Board.cpp Board.h BoardRow.h Coordinate.h IllegalCoordinateException.h 
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

BoardRow.o:BoardRow.cpp BoardRow.h Content.h
	$(CXX) $(CXXFLAGS) --compile BoardRow.cpp -o BoardRow.o

Content.o:Content.cpp Content.h IllegalCharException.h
	$(CXX) $(CXXFLAGS) --compile Content.cpp -o Content.o

llegalCoordinateException.o:IllegalCoordinateException.cpp IllegalCoordinateException.h 
	$(CXX) $(CXXFLAGS) --compile IllegalCoordinateException.cpp -o IllegalCoordinateException.o

Player.o:Player.cpp Player.h Board.h
	$(CXX) $(CXXFLAGS) --compile Player.cpp -o Player.o

Coordinate.o:Coordinate.cpp Coordinate.h 
	$(CXX) $(CXXFLAGS) --compile Coordinate.cpp -o Coordinate.o

Champion.o:Champion.cpp Champion.h Player.h 
	$(CXX) $(CXXFLAGS) --compile Champion.cpp -o Champion.o

TicTacToe.o:TicTacToe.cpp TicTacToe.h Player.h
	$(CXX) $(CXXFLAGS) --compile TicTacToe.cpp -o ticTacToe.o

DummyPlayers.o: DummyPlayers.cpp DummyPlayers.h Player.h 
	$(CXX) $(CXXFLAGS) --compile DummyPlayers.cpp -o DummyPlayers.o

main.o:main.cpp TicTacToe.h DummyPlayers.h Champion.h
	$(CXX) $(CXXFLAGS) --compile main.cpp -o main.o

Clean: 
	rm *.o a.out


buildAndRun: all main.o
	$(CXX) $(CXXFLAGS) main.o Board.o BoardRow.o Content.o IllegalCoordinateException.o 
	./a.out

