// A1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Erik Sistos
// Assignment 1 - Arrays
// 8-29-2020

#include <iostream>

//Function Prototype
int bubbleSort(long[], int);
int selectionSort(long[], int);

int main()
{
    int numExchanges = 0;             //Number of exchanges each array makes
    const int SIZE = 20;             //Array size

    //Unsorted bubbleSort array
    long bblSort[SIZE] = { 22, 29, 88, 65, 12, 72, 45, 126, 475, 3,
                          34, 35, 777, 500, 10, 412, 365, 800, 2, 5 };
    //Unsorted selectionSort array
    long selSort[SIZE] = { 22, 29, 88, 65, 12, 72, 45, 126, 475, 3,
                          34, 35, 777, 500, 10, 412, 365, 800, 2, 5 };

    //Get number of exchanges made by the bubble sort algorithm
    numExchanges = bubbleSort(bblSort, SIZE);

    //Output the exchanges made by bubble sort
    std::cout << "The bubble sort algorithm made " << numExchanges
        << " exchanges to sort the array in ascending order." << std::endl;

    //Get number of exchanges made by the selection sort algorithm
    numExchanges = selectionSort(selSort, SIZE);

    //Output the exchanges made by selection sort
    std::cout << "The selection sort algorithm made " << numExchanges
        << " exchanges to sort the array in ascending order." << std::endl;
    return 0;
}

//The bubbleSort function sorts an int array in ascending order
int bubbleSort(long arr[], int size)
{
    int maxElement;
    int index;
    int exchanges = 0;

    for (maxElement = size - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (arr[index] > arr[index + 1])
            {
                std::swap(arr[index], arr[index + 1]);
                exchanges++;
            }
        }
    }
    return exchanges;
}

//The selectionSort array sorts an int array in ascending order
int selectionSort(long arr[], int size)
{
    int minIndex;
    int minValue;
    int exchanges = 0;

    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = arr[start];
        for (int index = (start + 1); index < size; index++)
        {
            if (arr[index] < minValue)
            {
                minValue = arr[index];
                minIndex = index;
                exchanges++;
            }
        }
        std::swap(arr[minIndex], arr[start]);
    }
    return exchanges;
}