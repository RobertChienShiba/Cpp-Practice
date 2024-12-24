// ======================
// Programmer: 簡睿閎
// Date: 20230921
// File: LAB03DR10741071.cpp
// Description: a program to solve for the roots of a quadratic equation. 
// ======================

#include <iostream>
#include <cmath>
using namespace std;

int answer1;

// This program solves for the roots of a quadratic equation
int main(void){
    double a, b, c, disc, root1, root2;
    cout << "This program calculates the roots of a\n";
    cout << " quadratic equation of the form\n";
    cout << " 2\n";
    cout << " ax + bx + c = 0\n\n";
    cout << "Please enter values for a, b, and c: ";
    cin >> a >> b >> c;
    if (a == 0.0 && b == 0.0){
        answer1 = 0;
        cout << "The equation is degenerate and has no roots.\n";
    }
    else if (a == 0.0){
        answer1 = 1;
        cout << "The equation has the single root x = "
        << -c/b << endl;
    }
    else
    { // Start of compound statement for the outer else
        disc = pow(b,2.0) - 4 * a * c; // calculate discriminant
        if (disc > 0.0){
            answer1 = 2;
            disc = sqrt(disc);
            root1 = (-b + disc) / (2 * a);
            root2 = (-b - disc) / (2 * a);
            cout << "The two real roots are "
            << root1 << " and " << root2 << endl;
        }
        else if (disc < 0.0){
            answer1 = 0;
            cout << "Both roots are imaginary.\n";
        }
        else{
            answer1 = 1;
            cout << "Both roots are equal to " << -b / (2 * a) << endl;
        }
    } // End of compound statement for the outer else
    return 0;
}
