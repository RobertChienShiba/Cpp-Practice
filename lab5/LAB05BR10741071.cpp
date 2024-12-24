// ======================
// Programmer: 簡睿閎
// Date: 20231006
// File: LAB05BR10741071.cpp
// Description: Write a program to repetitively ask user to input the Fahrenheit temperature 4 times and call the tempvert(double inTemp) function for temperature conversion. 
// ======================

#include <iostream>
using namespace std;
double tempvert(double);  // function prototype
double answer1;           // This variable is for Autolab grading
int main()
{
    const int CONVERTS = 4;  // number of conversions to be made
    int count;           
    double fahren;

    for(count = 1; count <= CONVERTS; count++)
    {
        cout << "\nEnter a Fahrenheit temperature: ";
        cin  >> fahren;
        cout << "The Celsius equivalent is " << tempvert(fahren) << endl;
    }
    answer1 = tempvert(fahren);       // Save the last Celsius temperature for Autolab checking
    return 0;
}

double tempvert(double fahren)
{
    double celsius = (fahren - 32) * 5.0 / 9.0;
    return celsius;
}