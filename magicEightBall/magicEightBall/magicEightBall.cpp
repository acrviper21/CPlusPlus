// magicEightBall.cpp : This file contains the 'main' function. Program execution begins and ends there.
// By: Erik Sistos
// 6-24-2020
// This program mimics a magic eight ball and 
// picks a response randomly to an user question

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

int main()
{
    //Variables
    char userChoice = ' ';
    string question = "";
    vector<string> eightBallRepsonse;
    string response = "";
    srand(time(NULL));

    //Open file
    ifstream inputFile;
    inputFile.open("magicBallResponse.txt");

    //Input each line in file into a vector
    while (getline(inputFile, response))
    {
        eightBallRepsonse.push_back(response);
    }

    //Close file
    inputFile.close();

    //Display what the program is
    cout << "This is a magic eight ball. Ask me a question. " << endl;

    //Get question from user
    //Display random response from vector
    do
    {
        cout << "Enter a yes or no question: ";
        getline (cin, question);
        int responseNumber = rand() % (eightBallRepsonse.size() - 1) + 1;
        cout << eightBallRepsonse[responseNumber] << endl;
        
        //Ask user if they want to ask another question
        do
        {
            cout << "Ask another another question? (y or n): ";
            cin >> userChoice;
            userChoice = toupper(userChoice);
            cin.ignore();
        } while (userChoice != 'Y' && userChoice != 'N');
    } while (userChoice == 'Y');

    cout << "Thank you! Come back again! "<< endl;

    return 0;
}

