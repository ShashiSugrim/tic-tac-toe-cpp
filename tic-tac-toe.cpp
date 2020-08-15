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
        cout << "Column  1 2 3 \n";
        for (int x = 0; x < 3; x++)
        {
            cout << "Row #" + to_string(x + 1) + ": ";
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
    bool checkHorizontal(string player)
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
                return true;
            }
        }
        return false;
    }
    bool checkVertical(string player)
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
                return true;
            }
        }
        return false;
    }
    bool checkDiagonal(string player)
    {
        int numPlayer = 2;
        if (player == playerOne)
        {
            numPlayer == 1;
        }
        if (((board[0][0] == board[1][1]) && (board[2][2] == board[0][0])) && (board[0][0] != 0))
        {
            return true;
        }
        else if (((board[0][2] == board[1][1]) && (board[2][0] == board[0][2])) && (board[1][1] != 0))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Game mainGame;
    string playerOne;
    string playerTwo;
    string playerTurn;
    int colRegister;
    int rowRegister;
    int moveNum = 1;
    bool winner = false;
    cout << "\nWelcome to Tic Tac Toe!!!";
    cout << "\nPlayer Two will always make the first move";
    cout << "\nPlayer One is number 1 on the board";
    cout << "\nPlayer Two is number 2 on the board";
    cout << "\nWhat is player one's name?: ";
    cin >> playerOne;
    cout << "\nWhat is player twos's name?: ";
    cin >> playerTwo;
    mainGame.setPlayers(playerOne, playerTwo);

    mainGame.printBoard();
    while (!winner)
    {

        if (moveNum % 2 == 0)
        {
            playerTurn = playerOne;
            cout << "\nPlayer " + playerTurn + " is number 1 on the board";
        }
        else
        {
            playerTurn = playerTwo;
            cout << "\nPlayer " + playerTurn + " is number 2 on the board";
        }
        cout << "\n";
        cout << playerTurn + " makes move # " + to_string(moveNum);
        cout << "\n";
        cout << playerTurn + " choose column: ";
        cin >> colRegister;
        cout << "\n";
        cout << playerTurn + " choose row: ";
        cin >> rowRegister;
        colRegister -= 1;
        rowRegister -= 1;
        mainGame.setMove(playerTurn, colRegister, rowRegister);
        if (mainGame.checkVertical(playerTurn) || mainGame.checkHorizontal(playerTurn) || mainGame.checkDiagonal(playerTurn))
        {
            cout << "\n";
            cout << playerTurn + " has won the game in " + to_string(moveNum) + " moves!!!\n";
            winner = true;
        }
        mainGame.printBoard();
        moveNum++;
        cout << "\n-----------------------------------\n";
    }
}