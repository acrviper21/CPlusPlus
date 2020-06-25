// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
// By: Erik Sistos
// 6-24-2020
// This program is a simple tic-tac-toe game

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void displayIntro(string&, string&);
void displayBoard(char[], int);
bool playersMove(char[], int, string, int&, char, string, char);
bool isGameOver(char[], int, char, string, char, string);

int main()
{
    const int boardSize = 9;
    string firstPlayer = " ";
    string secondPlayer = " ";
    char board[boardSize] = { ' ', ' ', ' ',
                              ' ', ' ', ' ',
                              ' ', ' ', ' '};

    char playerOne = 'X';
    char playerTwo = 'O';
    bool gameOver = false;
    int playerMove;
    displayIntro(firstPlayer, secondPlayer);
    while (gameOver != true)
    {
        gameOver = playersMove(board, boardSize, firstPlayer, playerMove,
            playerOne, secondPlayer, playerTwo);
    }
    
    return 0;
}

void displayIntro(string& firstPlayer, string& secondPlayer)
{
    cout << "Welcome to TIC-TAC-TOE" << endl;
    cout << "Choose a  number between 1 and 9 to place your symbol on the board." << endl;
    cout << "Enter first players name: ";
    cin >> firstPlayer;
    cout << "Enter second players name: ";
    cin >> secondPlayer;
}
void displayBoard(char board[], int size)
{
    int count = 0;
    for (int index = 0; index < size; index++)
    {
        cout << "|" << board[index] << "|";
        count++;
        if (count % 3 ==0)
        {
            cout << endl;
        }
    }
}

bool playersMove(char board[], int boardSize, string firstPlayer, 
    int& playerMove, char playerOne, string secondPlayer, char playerTwo)
{
    bool gameOver = false;
    do
    {
        gameOver = isGameOver(board, boardSize, playerOne, firstPlayer, playerTwo, secondPlayer);
        if (gameOver)
        {
            return gameOver;
        }
        displayBoard(board, boardSize);
        cout << firstPlayer << " choose a number between 1 and 9: ";
        cin >> playerMove;
    } while ((playerMove < 1) || (playerMove > 9) || (board[playerMove - 1] == playerOne)
        || (board[playerMove - 1] == playerTwo));
    board[playerMove - 1] = playerOne;
    do
    {
        gameOver = isGameOver(board, boardSize, playerOne, firstPlayer, playerTwo, secondPlayer);
        if (gameOver)
        {
            return gameOver;
        }
         displayBoard(board, boardSize);
         cout << secondPlayer << " choose a number between 1 and 9: ";
         cin >> playerMove;
      
    } while ((playerMove < 1) || (playerMove > 9) || (board[playerMove - 1] == playerOne)
        || (board[playerMove - 1] == playerTwo));
    board[playerMove - 1] = playerTwo;
}

bool isGameOver(char board[], int boardSize, char playerOne, string firstPlayer,
    char playerTwo, string secondPlayer)
{
    bool gameOver = false;
    if (board[0] == playerOne && board[1] == playerOne && board[2] == playerOne)
    {
        displayBoard(board, boardSize);
        cout << firstPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[3] == playerOne && board[4] == playerOne && board[5] == playerOne)
    {
        displayBoard(board, boardSize);
        cout << firstPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[6] == playerOne && board[7] == playerOne && board[8] == playerOne)
    {
        displayBoard(board, boardSize);
        cout << firstPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[0] == playerOne && board[3] == playerOne && board[6] == playerOne)
    {
        displayBoard(board, boardSize);
        cout << firstPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[1] == playerOne && board[4] == playerOne && board[7] == playerOne)
    {
        displayBoard(board, boardSize);
        cout << firstPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[2] == playerOne && board[5] == playerOne && board[8] == playerOne)
    {
        displayBoard(board, boardSize);
        cout << firstPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[0] == playerOne && board[4] == playerOne && board[8] == playerOne)
    {
        displayBoard(board, boardSize);
        cout << firstPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[2] == playerOne && board[4] == playerOne && board[6] == playerOne)
    {
        displayBoard(board, boardSize);
        cout << firstPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[0] == playerTwo && board[1] == playerTwo && board[2] == playerTwo)
    {
        displayBoard(board, boardSize);
        cout << secondPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[3] == playerTwo && board[4] == playerTwo && board[5] == playerTwo)
    {
        displayBoard(board, boardSize);
        cout << secondPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[6] == playerTwo && board[7] == playerTwo && board[8] == playerTwo)
    {
        displayBoard(board, boardSize);
        cout << secondPlayer << " wins!! << endl";
        gameOver = true;
    }
    else if (board[0] == playerTwo && board[3] == playerTwo && board[6] == playerTwo)
    {
        displayBoard(board, boardSize);
        cout << secondPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[1] == playerTwo && board[4] == playerTwo && board[7] == playerTwo)
    {
        displayBoard(board, boardSize);
        cout << secondPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[2] == playerTwo && board[5] == playerTwo && board[8] == playerTwo)
    {
        displayBoard(board, boardSize);
        cout << secondPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[0] == playerTwo && board[4] == playerTwo && board[8] == playerTwo)
    {
        displayBoard(board, boardSize);
        cout << secondPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[2] == playerTwo && board[4] == playerTwo && board[6] == playerTwo)
    {
        displayBoard(board, boardSize);
        cout << secondPlayer << " wins!!" << endl;
        gameOver = true;
    }
    else if (board[0] != ' ' && board[1] != ' ' && board[2] != ' ' &&
             board[3] != ' ' && board[4] != ' ' && board[5] != ' ' && 
             board[6] != ' ' && board[7] != ' ' && board[8] != ' ')
    {
        displayBoard(board, boardSize);
        cout << "It's a tie" << endl;
        gameOver = true;
    }
    return gameOver;
}