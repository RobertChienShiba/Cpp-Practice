// ======================
// Programmer: 簡睿閎
// Date: 20230914
// File: a.cpp
// Description: a program for LAB02D
// ======================

#include <iostream>
using namespace std;

int main(){
    int divisor = 10000;// declare divisor of first digit
    int number;// remaining number for each digit
    cout << "Please input a five-digit number: ";
    cin >> number;// input number from user
    double digit;
    cout << "The five digits are as follows: ";
    while (number > 0)// When number is greater than 0, it means there are still digits that have not been printed out.
    {   
        digit = number / divisor;// Count each digit
        number = number % divisor;// remainder of number
        divisor = divisor / 10;// divisor of remaining digits
        cout << digit << " ";// print out digit
    }
    cout << endl;
    return 0;
}