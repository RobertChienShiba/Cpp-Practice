// ======================
// Programmer: 簡睿閎
// Date: 20231020
// File: LAB07AR10741071.cpp
// Description: Write a program that ask the user to input five temperatures and then calculate the average and maximum temperatures. 
// ======================
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

double answer1; 
int answer2;

int main(void)
{   
    const int inputLen = 5;
    int temperatures[inputLen] = {0};
    double total = 0, max = -INT32_MAX;

    for (int i = 0; i < inputLen; i++)
    {   
        cout << "Enter a temperature: ";
        cin >> temperatures[i];
        total += temperatures[i];
        max = temperatures[i] > max ? temperatures[i]:max;
    }
    cout << "The total of the temperature ";
    for (int j = 0; j < inputLen; j++)
    {
        cout << temperatures[j] << setw(3);
    }
    cout << " is " << total << endl; 
    answer1 = total / inputLen;
    answer2 = max;
    cout << "The average of temperature is: " << answer1 << endl;
    cout << "Max of temperature is: " << answer2 << endl;
    return 0;
}