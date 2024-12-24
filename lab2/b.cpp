// ======================
// Programmer: 簡睿閎
// Date: 20230914
// File: a.cpp
// Description: a program for LAB02B
// ======================

#include <iostream>
using namespace std;

double answer1;// autoLab will check whether answer1 variable is correct 
int main()
{
    double speed, fe, fr;
    fe = 2e10; //declare the constant value of f_e
    fr = 2.0000004e10;//declare the constant value of f_r
    speed = 6.685e8 * (fr - fe) / (fr + fe);//Put it into the formula to calculate the speed value
    cout << "The speed is " << speed << " miles/hour " << endl;
    answer1 = speed;//assign the value of speed to answer1
    return 0;
}