#ifndef TICTACTOE_H
#define TICTACTOE_H

#include"Player.h"



class TicTacToe
{
    int m_boardSize;
    Board m_board;
    Player* m_winner;
    Player* xPlayer;
    Player* oPlayer;
    bool foundAWinner;
    int numberOfPlayes;


    public:
        TicTacToe(int boardSize);
        ~TicTacToe();
        const Player& winner()const;
        const Board& board()const;
        void play(Player& xPlayer,Player& oPlayer);
        bool checkIfWon(Coordinate& turn,char charOfPlayer);



};

#endif // TICTACTOE_H_INCLUDED
