// ======================
// Programmer: 簡睿閎
// Date: 20230917
// File: HW01CR10741071.cpp
// Description: This is a program to determine the frequency returned by a car traveling at 55 mph.
// ======================

#include <iostream> // Includes the <iostream> library
#include <iomanip>  // Include the <iomanip> library for setprecision
using namespace std; // To set the standard library namespace std using cout and endl functions

double answer1; // Store the frequency corresponding to 55 mph in this global variable 

int main(void){
    double fe = 2e10; // Declare the value of 'fe' as 2e10
    double speed;// Declare the value if 'speed'
    cin >> speed; // Prompt the user to enter the value of 'speed' in miles per hour (mph)
    double fr = (-1 - speed / 6.685e8) * fe / (speed / 6.685e8 - 1); // // Calculate 'fr' using the provided formula
    cout << "The returned frequency corresponding to " 
            << speed << " mph is " << fr << " Hz\n";// Display the calculated frequency 'fr' corresponding to the input speed in mph
    cout << setprecision(16) <<"The returned frequency corresponding to " 
        << speed << " mph is " << fr << " Hz\n";// Display the calculated frequency 'fr' with extended precision
    answer1 = fr;// Set 'answer1' to the value of 'fr'
    return 0;// Return 0 to indicate successful program execution
}