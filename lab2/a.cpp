// ======================
// Programmer: 簡睿閎
// Date: 20230914
// File: a.cpp
// Description: a program for LAB02A
// ======================

#include <iostream>
using namespace std;

double answer1, answer2;// autoLab will check whether answer1 & answer2 variable is correct 

int main()
{
    double grade1; // declare grade1 as a double variable
    double grade2; // declare grade2 as a double variable
    double total; // declare total as a double variable
    double average; // declare average as a double variable
    grade1 = 85.5;
    grade2 = 97.0;
    total = grade1 + grade2;
    average = total / 2.0; // divide the total by 2.0
    cout << "The average grade is " << average << endl;
    answer1 = total; //assign the value of the sum to answer1
    answer2 = average; //assign the value of average to answer2
    return 0;
}
