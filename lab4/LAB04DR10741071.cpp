// ======================
// Programmer: 簡睿閎
// Date: 20230928
// File: LAB04DR10741071.cpp
// Description: Write a program that continuously requests input of grades and checks the correctness of the input.
// ======================

#include <iostream>
#include<iomanip>
using namespace std;

double answer1;

int main(void){
    double grade;
    double total = 0;
    int count = 0;
    do
    {
        cout << "\nEnter a grade (enter 999 to exit): ";
        cin >> grade;
        if (grade == 999)
            break;
        else if (grade <= 100 && grade >= 0){
            total += grade;
            count += 1;
        }
        else
            cout << "An invalid grade has been entered! " << "Please reenter a valid grade." << endl;
    } while (1);
    answer1 = total / count;
    cout << "The average of the valid grades entered is: " << answer1 << endl;
    return 0;
}