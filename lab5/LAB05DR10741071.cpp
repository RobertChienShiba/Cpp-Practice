// ======================
// Programmer: 簡睿閎
// Date: 20231006
// File: LAB05BR10741071.cpp
// Description: Write a program to find the greatest common divisor (GCD) of two positive integers.
// ======================

#include <iostream>
using namespace std;

void swap(int&, int&);
int gcd(int, int);
int answer1;

int main(void)
{
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    if (num1 < num2)
        swap(num1, num2);
    answer1 = gcd(num1, num2);
    cout << "The gcd of " << num1 << " and " << num2 << " is: " << answer1 << endl;
    return 0;
}

void swap(int& first, int& second)
{
    int temp;
    temp = first; // save first's value
    first = second; // store second's value in first
    second = temp; // change second's value
    return;
}

int gcd(int num1, int num2)
{   
    int remainder;
    while((remainder = num1 % num2) > 0)
    {
        num1 = num2;
        num2 = remainder;
    }
    return num2;
}
