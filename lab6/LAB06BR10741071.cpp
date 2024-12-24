// ======================
// Programmer: 簡睿閎
// Date: 20231012
// File: LAB06BR10741071.cpp
// Description: Write a driver program that will produce the Fibonacci series up to 20 terms. 
// ======================

#include <iostream>
using namespace std;

double fibonacci(int n);
double answer1;

int main(void)
{   
    answer1 = fibonacci(19);
    cout << "Fibonacci Series of 20 terms: " << answer1 << endl;
    return 0;
}

double fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (fibonacci(n - 1) + fibonacci(n - 2));
}