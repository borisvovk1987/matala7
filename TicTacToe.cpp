#include"TicTacToe.h"

TicTacToe::TicTacToe(int boardSize)
{
    Board temp{boardSize};
    m_board=temp;
    std::cout<<m_board;
}

TicTacToe::~TicTacToe()
{

}

const Player& TicTacToe::winner()const
{

    return *m_winner;
}

const Board& TicTacToe:: board()const
{
    return m_board;
}

void TicTacToe::play(Player& xPlayer ,Player& oPlayer)
{
    m_board='.';
    m_winner=&oPlayer;
    foundAWinner=false;
    numberOfPlayes=0;
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    Coordinate turn{0,0};

    // keep the loop until both the cases are true:
    // first case is that the number of player smaller then the number of tiiles
    // second is that the winner wasn't bean found
    while(numberOfPlayes!=(m_board.size()*m_board.size()) && !foundAWinner)
    {

        // X Player turn
        try
        {
            turn= xPlayer.play(m_board);
            if(m_board[turn]!='.')
            {
                foundAWinner=true;
                m_winner=&oPlayer;
                break;
            }
            numberOfPlayes++;
            m_board[turn]='X';
            if(checkIfWon(turn,'X'))
            {
                foundAWinner=true;
                m_winner=&xPlayer;
                break;
            }



        }
        catch(const string ex)
        {
            m_winner=&oPlayer;
             break;

        }
        // O player turn
         try
        {
           turn= oPlayer.play(m_board);
           if(m_board[turn]!='.')
           {
                foundAWinner=true;
                m_winner=&xPlayer;
                break;

           }
            numberOfPlayes++;
            m_board[turn]='O';
            if(checkIfWon(turn,'O'))
            {
                foundAWinner=true;
                m_winner=&oPlayer;
                break;
            }



        }
        catch(const string ex)
        {
            m_winner=&xPlayer;
            break;


        }
        //std::cout<<m_board<<"\n";

    }





}


//This function checks if the player had won or not
//The function checks if the square that had been picked matches the squares in the
// same colom or row or in one of the diagonals .
bool TicTacToe::checkIfWon(Coordinate& turn,char charOfPlayer)
{

    //this loop checks the row of the current coordinate.
    bool check=true;
    for(int i=0;i<m_board.size();i++)
    {
        if(m_board[{turn.getX(),i}]!=charOfPlayer)
        {
            check=false;
            break;
        }
    }
    if(check)
    {
        return true;
    }



    // this loop checks the colom of the current coordinate.
    check=true;
    for(int i=0;i<m_board.size();i++)
    {
        if(charOfPlayer!=m_board[{i,turn.getY()}])
        {
            check=false;
            break;
        }

    }
    if(check)
    {
        return true;
    }


    // This section checks of one of the diagonals brings the victory .


    check=true;
    for(int i=0;i<m_board.size();i++)
    {
        if(charOfPlayer!=m_board[{i,i}])
        {
            check=false;
            break;
        }

    }
    if(check)
    {
        return true;
    }

    check=true;
    int i=m_board.size()-1;
    int j=0;
    while(i>0)
    {
        if(charOfPlayer!=m_board[{i,j}])
        {
            check= false;
            break;


        }
        i--;
        j++;
    }
    if(check)
    {
        return true;
    }




    return check;


}
