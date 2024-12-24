// ======================
// Programmer: 簡睿閎
// Date: 20230921
// File: LAB03DR10741071.cpp
// Description: A program ask for three integer values, num1, num2, and num3, and display them in decreasing order. 
// ======================

#include <iostream>
#include <cmath>
using namespace std;

int answer1, answer2;

int main(void){
    int num1, num2, num3, temp;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    if (num1 > num2){
        temp = num1;
        num1 = num2;
        num2 = temp;   
    }
    if (num1 > num3){
        temp = num1;
        num1 = num3;
        num3 = temp;   
    }
    if (num2 > num3){
        temp = num2;
        num2 = num3;
        num3 = temp;   
    }
    cout << "The three numbers in descending order: " << num3 << " " <<  num2 << " " << num1 << endl;
    answer1 = num3;
    answer2 = num1;
    return 0;
}