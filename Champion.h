#ifndef CHAMPION_H
#define CHAMPION_H

#include "Player.h"
//#include "Coordinate.h"
//include "Board.h"

class Champion:public Player
{

public:
     const string name() const override
    {
        return "Daniel Vovk";
    }
    const Coordinate play(const Board& board)override;

};


#endif // CHAMPION_H_INCLUDED



// need to see if i need a destracure
