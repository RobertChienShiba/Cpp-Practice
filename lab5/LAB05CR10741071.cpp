// ======================
// Programmer: 簡睿閎
// Date: 20231006
// File: LAB05BR10741071.cpp
// Description: Write a program to ask the user to input two numbers and call the function. Display the values of the two input numbers before and after the function is called .
// ======================

#include <iostream>
using namespace std;

void swap(double&, double&);   // function receives 2 references
double answer1, answer2;       // These variables are for Autolab grading
int main()
{
    double firstnum, secnum;
    cout << "Please input two numbers: ";
    cin >> firstnum >> secnum;

    cout << endl << "The value stored in firstnum is: " << firstnum << endl;
    cout << "The value stored in secnum is: "<< secnum << "\n\n";
    swap(firstnum, secnum);   // call the function with references
    cout << "The value stored in firstnum is now: " << firstnum << endl;
    cout << "The value stored in secnum is now: " << secnum << endl;
    answer1 = firstnum;       // Save for Autolab checking
    answer2 = secnum;         // Save for Autolab checking
    return 0;
}

void swap(double& first, double& second)
{
    double temp;
    temp = first; // save first's value
    first = second; // store second's value in first
    second = temp; // change second's value
    return;
}
