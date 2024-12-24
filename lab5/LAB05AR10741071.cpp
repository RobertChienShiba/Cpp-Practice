// ======================
// Programmer: 簡睿閎
// Date: 20231006
// File: LAB05AR10741071.cpp
// Description: Write a program to ask the user to input two integers and call this function to print the maximum number.
// ======================

#include <iostream>
using namespace std;

int findMax(int, int);  // the function prototype
int answer1;            // This variable is for Autolab grading

int main()
{
    int firstnum, secnum;

    cout << "\nEnter a number: ";
    cin  >> firstnum;
    cout << "Great! Please enter a second number: ";
    cin  >> secnum;

    answer1 = findMax(firstnum, secnum); // the function is called here

    return 0;
}

int findMax(int x, int y)
{                  // start of function body
    int maxnum;      // variable declaration

    if (x >= y)      // find the maximum number
        maxnum = x;
    else
        maxnum = y;

    cout << "\nThe maximum of the two numbers is " << maxnum << endl;

    return maxnum;
}  // end of function body and end of function
