// ======================
// Programmer: 簡睿閎
// Date: 20231006
// File: LAB05BR10741071.cpp
// Description: Write a C++ program that accepts the value of the circumference from the user, calculates the radius and area, and displays the calculated values of a and r. 
// ======================

#include <iostream>
#include <cmath>
using namespace std;
#define pi M_PI

void circle_area( double& a, double& r, double c);
double circle_radius(double c);
double answer1, answer2;

int main(void)
{
    double a, r, c;
    cout << "Enter the circumference: ";
    cin >> c;
    circle_area(a, r, c);
    answer1 = r;
    answer2 = a;
    return 0;
}

void circle_area(double& a, double& r, double c)
{
    r = circle_radius(c);
    cout << "For a circle with circumference of " << c << endl;
    cout << "The radius is: " << r << endl;
    a = pi * pow(r, 2);
    cout << "The area is: " << a << endl;
}

double circle_radius(double c)
{
    return c / (2.0 * pi);
}