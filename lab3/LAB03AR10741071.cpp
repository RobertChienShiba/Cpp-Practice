// ======================
// Programmer: 簡睿閎
// Date: 20230921
// File: LAB03AR10741071.cpp
// Description: a program for check whether circle area is valid or not.
// ======================

#include <iostream>
#include <cmath>
using namespace std;

double answer1;

int main(){
    double radius;
    cin >> radius;
    if (radius < 0){
        cout << "A negative radius is invalid" << endl;
    }
    else{
        answer1 = 3.1416 * pow(radius, 2);
        cout << "The area of this circle is " << answer1 << endl;
    }
    return 0;
}