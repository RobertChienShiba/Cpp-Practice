// ======================
// Programmer: 簡睿閎
// Date: 20230917
// File: HW01BR10741071.cpp
// Description: This is a program that handles the addition and averaging of three variables
// ======================

#include <iostream> // This is a C++ program that includes the iostream library
using namespace std; // To set the standard library namespace std using cout and endl functions

double answer1; // Store the sum of the three numbers in this global variable 
double answer2; // Store the average of the three numbers in this global variable

int main(void) {
    double num1, num2, num3; // Declare three double variables to store input

    cin >> num1 >> num2 >> num3; // Prompt the user to enter three numbers, and store them in the variables.

    answer1 = num1 + num2 + num3; // Calculate the sum of the three numbers.

    answer2 = answer1 / 3; // Calculate the average of the three numbers.

    cout << "The sum of the three numbers is " << answer1 << "." << endl; // Display the sum of the three numbers.

    cout << "The average of the three numbers is " << answer2 << "." << endl; // Display the average of the three numbers.

    return 0; // Return 0 to indicate successful program execution.
}
