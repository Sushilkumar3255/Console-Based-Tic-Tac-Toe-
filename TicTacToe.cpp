#include <bits/stdc++.h>

using namespace std;

class TicTacToe
{
private:
    deque<deque<char>> board;
    string Player1;
    string Player2;
    int firstMove, CurrentPlayer;
    int Player1Wins;
    int Player2Wins;
    int boardsize;
    stack<vector<int>> Moves;

public:
    TicTacToe()
    {
        for (int i = 0; i < 3; i++)
        {
            deque<char> inboard;
            for (int j = 0; j < 3; j++)
            {
                inboard.push_back(' ');
            }
            board.push_back(inboard);
        }

        firstMove = -1;
        Player1 = "";
        Player2 = "";
        CurrentPlayer = -1;
        Player1Wins = 0;
        Player2Wins = 0;
        boardsize = 3;
    }
    void Start()
    {
        while (firstMove == -1)
        {
            cout << "Provide who want to take first move (Provide name) : ";
            string move;
            cin >> move;
            if (move == Player1)
            {
                firstMove = 0;
            }
            else if (move == Player2)
            {
                firstMove = 1;
            }
            else
            {
                cout << "===================================================================================" << endl;
                cout << "                    * error : Pls enter same name as given before..                " << endl;
                cout << "===================================================================================" << endl;
            }
        }
        cout << endl;
        cout << "Provide board size ( n X n ) : ";
        cin >> boardsize;
        if (boardsize <= 0)
        {
            boardsize = 3;
            cout << "===================================================================================" << endl;
            cout << "         * error : Your entry is Invalid so board size is by default 3..           " << endl;
            cout << "===================================================================================" << endl;
        }
        else
        {
            deque<deque<char>> newboard;
            for (int i = 0; i < boardsize; i++)
            {
                deque<char> inboard;
                for (int j = 0; j < boardsize; j++)
                {
                    inboard.push_back(' ');
                }
                newboard.push_back(inboard);
            }
            board = newboard;
        }

        if (firstMove == 0)
        {
            cout << Player1 << " has choosen to move first" << endl;
        }
        else
        {
            cout << Player2 << " has choosen to move first" << endl;
        }
        cout << endl;
        CurrentPlayer = firstMove;
    }
    void Reset()
    {
        for (int i = 0; i < boardsize; i++)
        {
            for (int j = 0; j < boardsize; j++)
            {
                board[i][j] = ' ';
            }
        }

        CurrentPlayer = -1;
        while (!Moves.empty())
        {
            Moves.pop();
        }
    }
    void checkWin()
    {
        bool h = false;
        for (int i = 0; i < boardsize; i++)
        {
            char chlr = (board[i][0] == ' ' ? '@' : board[i][0]);
            char chtb = (board[0][i] == ' ' ? '@' : board[0][i]);
            bool checkerlr = true;
            bool checkertb = true;
            for (int j = 1; j < boardsize; j++)
            {
                if (board[i][j] != chlr)
                {
                    checkerlr = false;
                }
                if (board[j][i] != chtb)
                {
                    checkertb = false;
                }
            }
            h |= (checkerlr || checkertb);
        }
        char chdiagonalTopLefttoBottomRight = (board[0][0] == ' ' ? '@' : board[0][0]);
        char chdiagonalBottomLefttoTopRight = (board[0][2] == ' ' ? '@' : board[0][2]);
        bool checkerdiagonalTopLefttoBottomRight = true;
        bool checkerdiagonalBottomLefttoTopRight = true;
        for (int i = 0; i < boardsize; i++)
        {
            if (chdiagonalTopLefttoBottomRight != board[i][i])
            {
                checkerdiagonalTopLefttoBottomRight = false;
            }
            if (chdiagonalBottomLefttoTopRight != board[i][2 - i])
            {
                checkerdiagonalBottomLefttoTopRight = false;
            }
        }
        h |= (checkerdiagonalTopLefttoBottomRight || checkerdiagonalBottomLefttoTopRight);
        if (h)
        {

            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << endl;
            cout << "                  " << (CurrentPlayer == 0 ? Player1 : Player2) << " has won the match..." << endl;
            cout << endl;
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << endl;
            if (CurrentPlayer == 0)
            {
                Player1Wins++;
            }
            else
            {
                Player2Wins++;
            }

            Reset();
        }
    }
    void getDetails()
    {
        string name;
        cout << "Provide Player 1 name : ";
        cin >> name;
        Player1 = name;
        cout << "Provide Player 2 name : ";
        cin >> name;
        Player2 = name;
        cout << endl;
        cout << "Welcome " << Player1 << " and " << Player2 << " !!" << endl;
        cout << " * " << Player1 << " your Symbol is : O" << endl;
        cout << " * " << Player2 << " your Symbol is : X" << endl;
        cout << endl;
    }
    void PrintBoard()
    {
        cout<<endl;
        for (int i = 0; i < boardsize; i++)
        {
            cout << " ";
            for (int j = 0; j < boardsize; j++)
            {
                cout << " ---";
            }
            cout << endl;
            cout << " | ";
            for (int j = 0; j < boardsize; j++)
            {
                cout << board[j][i] << " | ";
            }
            cout << endl;
        }
        cout << " ";
        for (int j = 0; j < boardsize; j++)
        {
            cout << " ---";
        }
        cout << endl;
    }
    void Makemove()
    {
        if (CurrentPlayer == -1)
        {

            cout << "===================================================================================" << endl;
            cout << "   * error : Game not yet started Pls Start the game before you make any move..    " << endl;
            cout << "===================================================================================" << endl;
            return;
        }

        int x, y;
        cout << (CurrentPlayer == 0 ? Player1 : Player2) << " enter x and y coordinates with space: ";
        cin >> x >> y;
        if (x >= 3 || x < 0 || y >= 3 || y < 0)
        {

            cout << "==========================================================================" << endl;
            cout << "              * error : Enter valid place to make move                    " << endl;
            cout << "==========================================================================" << endl;
        }
        else if (!(board[x][y] == ' '))
        {
            cout << "==========================================================================" << endl;
            cout << "       * error : Enter place you made move is already beeen taken         " << endl;
            cout << "==========================================================================" << endl;
        }
        else
        {
            board[x][y] = (CurrentPlayer == 0 ? 'O' : 'X');
            PrintBoard();
            cout << endl;
            checkWin();
            Moves.push({x, y});
            CurrentPlayer = (CurrentPlayer + 1) % 2;
        }
    }
    void Undo()
    {
        if (Moves.empty())
        {
            cout << "==============================================================" << endl;
            cout << "             * error : There is no move to Undo               " << endl;
            cout << "==============================================================" << endl;
            return;
        }

        vector<int> moveToRemove = Moves.top();
        board[moveToRemove[0]][moveToRemove[1]] = ' ';
        Moves.pop();
        cout << "=========================================================" << endl;
        cout << "                 * Success : Undo Successfully             " << endl;
        cout << "=========================================================" << endl;
    }
    void Status(){
        cout<<"######################################################################################"<<endl;
        cout<<"######################################################################################"<<endl;
        cout<<endl;
        cout<<"                             "<<Player1<<" wins ("<<Player1Wins<<") and "<<Player2<<" wins("<<Player2Wins<<")"<<endl;
        cout<<endl;
        cout<<"######################################################################################"<<endl;
        cout<<"######################################################################################"<<endl;
        cout<<endl;
    }
};

int main()
{

    TicTacToe boar;
    boar.getDetails();
    while (true)
    {
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "       # Option Start : To Start the Game" << endl;
        cout << "       # Option ShBoard : To Show Board" << endl;
        cout << "       # Option Exit : To Quit Game" << endl;
        cout << "       # Option Move : To Make Move" << endl;
        cout << "       # Option Undo : To Undo Move" << endl;
        cout << "       # Option Status : To Show Status Move" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
        string inp;
        cout << "Enter option to choose : ";
        cin >> inp;
        if (inp == "ShBoard")
        {
            boar.PrintBoard();
        }
        else if (inp == "Exit")
        {
            break;
        }
        else if (inp == "Move")
        {
            boar.Makemove();
        }
        else if (inp == "Start")
        {
            boar.Start();
        }
        else if (inp == "Undo")
        {
            boar.Undo();
        }
        else if (inp == "Status")
        {
            boar.Status();
        }
        else
        {
            cout << " * error : Enter Valid Data.." << endl;
        }
    }
}