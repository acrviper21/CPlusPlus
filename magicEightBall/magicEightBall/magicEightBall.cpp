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
    char userChoice = ' ';
    string question = "";
    vector<string> eightBallRepsonse;
    string response = "";
    ifstream inputFile;
    inputFile.open("magicBallResponse.txt");
    srand(time(NULL));

    while (getline(inputFile, response))
    {
        eightBallRepsonse.push_back(response);
    }
    inputFile.close();

    cout << "This is a magic eight ball. Ask me a question. " << endl;
    do
    {
        cout << "Enter a yes or no question: ";
        getline (cin, question);
        int responseNumber = rand() % (eightBallRepsonse.size() - 1) + 1;
        cout << eightBallRepsonse[responseNumber] << endl;
        do
        {
            cout << "Ask another another question? (y or n): ";
            cin >> userChoice;
            userChoice = toupper(userChoice);
            cin.ignore();
        } while (userChoice != 'Y' && userChoice != 'N');
    } while (userChoice == 'Y');

    cout << "Thank you! Come back again! "<< endl;
}

