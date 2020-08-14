#include <iostream>
#include <string>

using namespace std;

class Game
{
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    string playerOne, playerTwo;

public:
    void setPlayers(string p1, string p2)
    {
        playerOne = p1;
        playerTwo = p2;
        return;
    }
    void printBoard()
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                cout << to_string(board[x][y]) + " ";
            }
            cout << "\n";
        }
        return;
    }
    void setMove(string player, int col, int row)
    {
        if (col > 2 || col < 0)
        {
            cout << "\nColumn invalid";
        }
        else if (row > 2 || row < 0)
        {
            cout << "\nRow invalid";
        }
        else
        {
            if (player == playerOne)
            {
                board[row][col] = 1;
            }
            if (player == playerTwo)
            {
                board[row][col] = 2;
            }
        }
        return;
    }
    string checkHorizontal(string player)
    {
        int numPlayer = 2;
        if (player == playerOne)
        {
            numPlayer == 1;
        }
        for (int i = 0; i < 3; i++)
        {
            if (((board[i][0] == board[i][1]) && (board[i][2] == board[i][0])) && (board[i][0] != 0))
            {
                return "win horizontal";
            }
        }
        return "nowin horizontal";
    }
    string checkVertical(string player)
    {
        int numPlayer = 2;
        if (player == playerOne)
        {
            numPlayer == 1;
        }
        for (int i = 0; i < 3; i++)
        {
            if (((board[0][i] == board[1][i]) && (board[2][i] == board[0][i])) && (board[0][i] != 0))
            {
                return "win vertical";
            }
        }
        return "nowin vertical";
    }
};

int main()
{
    Game mainGame;
    string playerOne;
    string playerTwo;
    int moveNum = 1;
    bool winner = false;
    cout << "\nWelcome to Tic Tac Toe!!!";
    cout << "\nWhat is player one's name?: ";
    cin >> playerOne;
    cout << "\nWhat is player twos's name?: ";
    cin >> playerTwo;
    mainGame.setPlayers(playerOne, playerTwo);
    mainGame.printBoard();
    cout << "\nMove set by Player 1\n";
    mainGame.setMove(playerOne, 2, 0);
    mainGame.setMove(playerOne, 2, 1);
    mainGame.setMove(playerOne, 2, 2);
    mainGame.printBoard();
    cout << "\n" + mainGame.checkHorizontal(playerOne) + "\n";
    cout << "\n" + mainGame.checkVertical(playerOne) + "\n";
}