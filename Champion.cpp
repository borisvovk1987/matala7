#include "Champion.h"

const Coordinate Champion::play(const Board& board)
{
    if(board[{board.size()-1,0}]=='.')
    {
        Coordinate c{board.size()-1,0};
        return c;
    }
    else if(board[{0,board.size()-1}]=='.')
    {
        Coordinate c{0,board.size()-1};
        return c;
    }
    else
    {
        int x=board.size()-1,y=0;
        while(x>=0)
        {
            Coordinate c{x,y};
            if(board[{x,y}]=='.')
            {
                return c;
            }
            x--;
            y++;

        }
    }
    return {0,0};

}
