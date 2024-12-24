// ======================
// Programmer: 簡睿閎
// Date: 20230917
// File: HW01BR10741071.cpp
// Description: This is a program that computes the maximum load in lbs
// ======================

#include <iostream> // This is a C++ program that includes the iostream library
using namespace std; // To set the standard library namespace std using cout, endl and cin functions

double answer1; // Store the value of the maximum load in lbs in this global variable

int main(void){
    double S; // Declare a double variable to store the stress in lbs/in2 
    double d; // Declare a double variable to store the distance in inches that the load is placed from the fixed end of the beam
    double height; // Declare a double variable to store the height of a symmetrical wooden beam
    double base; // Declare a double variable to store the base of a symmetrical wooden beam
    cin >> d >> base >> height >> S; // The input sequence is distance (d), base, height, and stress (S), respectively
    double c = height / 2; // Assign one-half the height to c
    double I = (base * height * height * height) / 12; // Use the formula to calculate the beam’s rectangular moment of inertia in units of in4
    d = d * 12; // Convert foot to inches
    double L = (S * I) / (d * c) ; // Use the formula to calculate the maximum weight in lbs of the load placed on the beam
    cout << "The maximum load is " << L << "lbs." << endl; // Display the maximum weight in lbs of the load placed on the beam
    answer1 = L; // Assign the maximum weight in lbs of the load placed on the beam to answer1
    return 0; // Return 0 to indicate successful program execution.
}