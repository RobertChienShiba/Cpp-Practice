// ======================
// Programmer: 簡睿閎
// Date: 20230914
// File: a.cpp
// Description: a program for LAB02C
// ======================

#include <iostream>
using namespace std;
double answer1;

int main(){
    double F;// declare the value of Fahrenheit
    double C;// declare the value of Celsius;
    cout << "Please input a Fahrenheit temperature: ";
    cin >> F;// input Fahrenheit temperature from user
    C = (F - 32) * 5 / 9;//Put it into the formula to calculate the Celsius value
    cout << "For a Fahrenheit temperature of " << F << " degrees," << endl;// print out Fahrenheit temperature!!
    cout << "the equivalent Celsius temperature is " << C << " degrees" << endl;// print out Celsius temperature!!
    answer1 = C;//assign the value of Celsius to answer1
    return 0;
}