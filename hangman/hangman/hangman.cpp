// hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
// By: Erik Sistos
// 6-25-2020
// The user inputs a letter and try to guess the word in a certain amount of guesses

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;

int main()
{
	//Variables
	string hangmanWord = "";
	string outputWord ="";
	string wordList = "";
	char guess = ' ';
	char underscore = '_';
	bool gameOver = false;
	int randomWordPos = 0;
	int numberOfLives = 5;
	int count = 0;
	srand(time(NULL));

	//Open file
	ifstream inputFile;
	inputFile.open("wordList.txt");
	
	//Choose random word from list
	randomWordPos = rand() % 117 + 0;
	
	//Get random word from list
	for (int lineNo = 0; getline(inputFile, wordList) && lineNo <= randomWordPos; lineNo++)
	{
		if (lineNo == randomWordPos)
		{
			hangmanWord = wordList;
		}
	}

	//Close file
	inputFile.close();

	//Display underscores as blanks for the word length
	for (int index = 0; index < hangmanWord.length(); index++)
	{
		cout << underscore << " ";
		outputWord.push_back(underscore);
	}

	cout << endl;

	do
	{
		//Display lives and get user input
		cout << "Lives: " << numberOfLives << endl;
		cout << "Pick a random letter to start guessing: ";
		cin >> guess;
		count = 0;

		//Loop through each index of the word
		for (int index = 0; index < hangmanWord.length(); index++)
		{
			//Compare letter to each word index to see if it matches
			if (guess == hangmanWord[index])
			{
				//Use to determine wheter a life is lost or not
				count++;
				//Displays the letter if it matches instead of the underscore
				outputWord[index] = hangmanWord[index];
				cout << outputWord[index] << " ";
			}
			//Display underscores if the letter doesn't match the index
			else if (guess != hangmanWord[index])
			{
				cout << outputWord[index] << " ";
			}
		}
		//Lose a life if the letter was not inside the word at all
		if (count < 1)
		{
			numberOfLives -= 1;
		}
		cout << endl;
		for (int index = 0; index < hangmanWord.length(); index++)
		{
			//Game is over if user guessed the word
			if (hangmanWord == outputWord)
			{
				gameOver = true;
			}
			//Game continues if user hasn't guessed the right word
			else if (hangmanWord != outputWord)
			{
				gameOver = false;
			}
		}
		//User loses if the lose all their lives
		if (numberOfLives < 1)
		{
			cout << "You lose. The word was " << hangmanWord << endl;
			gameOver = true;
		}

	} while (gameOver != true);
	
	//If user guesses the word without losing all 
	//their lives they win
	if (hangmanWord == outputWord)
	{
		cout << "You Win!! " << endl;
	}
	return 0;
}

