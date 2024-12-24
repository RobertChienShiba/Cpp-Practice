// ======================
// Programmer: 簡睿閎
// Date: 20230921
// File: LAB03BR10741071.cpp
// Description: a program to display an item’s specification status corresponding to a letter input.
// ======================

#include <iostream>
using namespace std;

char answer1;

int main(){
    cout << "Enter a specification answer1: ";
    cin >> answer1;
    if(answer1 == 'S')
        cout << "The item is space exploration grade.";
    else if(answer1 == 'M')
        cout << "The item is military grade.";
    else if(answer1 == 'C')
        cout << "The item is commercial grade.";
    else if(answer1 == 'T')
        cout << "The item is toy grade.";
    else
        cout << "An invalid answer1 was entered.";
    cout << endl;

    return 0;
}