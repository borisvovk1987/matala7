#ifndef BOARD_H
#define BOARD_H

#include "Coordinate.h"
#include"BoardRow.h"
#include"IllegalCoordinateException.h"

#include<vector>
#include<iostream>


class Board
{
private:
    int m_boardSize;
    BoardRow* m_board;


public:

    Board();
    Board(int boardSize);
    Board(const Board &other);

    ~Board();
    friend std::ostream& operator<<(std::ostream& out,const Board& board );
    Board& operator=(const Board&  other );
    Board& operator=(const char cha);
    Content& operator[](Coordinate coordinate)const;
    int size()const;


};



#endif
