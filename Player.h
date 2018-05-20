#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"
//#include "Coordinate.h"

using namespace std;

class Player
{
protected:
    char myChar;

public:

    Player();
    ~Player();
    virtual const string name()const=0;
    virtual const Coordinate play(const Board& board)=0;
    char getChar()const;
    void setChar(char xy);

};


#endif // PLAYER_H_INCLUDED
