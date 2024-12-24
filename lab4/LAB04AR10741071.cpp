// ======================
// Programmer: 簡睿閎
// Date: 20230928
// File: LAB04AR10741071.cpp
// Description: Write a program allowing the user to input four numbers and calculate the sum of the four numbers.
// ======================

#include <iostream>
using namespace std;
double answer1;

int main(void){
    const int maxInput = 4;
    int count = 1;
    double total;
    cout << "This program will ask you to enter " << maxInput << " numbers." << endl;
    while (count <= maxInput){
        double num;
        cout << "Enter a number: ";
        cin >> num;
        total += num;
        cout << "The total is now " << total << endl;
        count++ ;
    }
    cout << "The final total is " << total << endl;
    answer1 = total;
    return 0;
}