// ======================
// Programmer: 簡睿閎
// Date: 20231012
// File: LAB06CR10741071.cpp
// Description: Write a driver program to input the two integers and call the recursive function to find the GCD of the two input integers.
// ======================

#include <iostream>
using namespace std;

int euclidAlgorithm(int, int);
void swap(int&, int&);
int answer1;

int main(void)
{
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1 >> num2;
    if (num1 < num2)
        swap(num1, num2);
    answer1 = euclidAlgorithm(num1, num2);
    cout << "Enter the second number: The gcd of " << num1 << " and " << num2\
    << " is: " << answer1 << endl;
    return 0;
}

int euclidAlgorithm(int a, int b)
{
    if (b == 0)
        return a;
    int temp = b;
    b = a % b;
    a = temp;
    return euclidAlgorithm(a, b);
}

void swap(int& a, int& b)
{
    int temp;
    temp = a; // save first's value
    a = b; // store second's value in first
    b = temp; // change second's value
    return;
}