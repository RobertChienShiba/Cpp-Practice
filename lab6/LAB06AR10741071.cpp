// ======================
// Programmer: 簡睿閎
// Date: 20231012
// File: LAB06AR10741071.cpp
// Description: Write a function template to swap two numbers of different data types. 
// ======================

#include <iostream>
#include <iomanip>
using namespace std;

double answer1, answer2;

template <class T>

void mySwap(T& a, T& b)
{
    T temp;
    temp = a; // save first's value
    a = b; // store second's value in first
    b = temp; // change second's value
    return;
}

int main(void)
{
    char a1 = 'X', b1 = 'Y';
    int a2 = 10, b2 = 20;
    float a3 = 70.1f, b3 = 35.2f;
    double a4 = 23.23236, b4 = 11.02345;

    cout << "Before swapping the number(char): a1 = " << a1 << " b1 = " << b1 << endl;
    mySwap<char>(a1, b1);
    cout << "After swapping the number(char): a1 = " << a1  << " b1 = " << b1 << endl;

    cout << "Before swapping the number(int): a2 = " << a2 << " b2 = " << b2 << endl;
    mySwap<int>(a2, b2);
    cout << "After swapping the number(int): a2 = " << a2  << " b2 = " << b2 << endl;

    cout << "Before swapping the number(float): a3 = " << a3 << " b3 = " << b3 << endl;
    mySwap<float>(a3, b3);
    cout << "After swapping the number(float): a3 = " << a3  << " b3 = " << b3 << endl;

    cout << "Before swapping the number(double): a4 = " << a4 << " b4= " << b4 << endl;
    mySwap<double>(a4, b4);
    cout << "After swapping the number(double): a4 = " << a4  << " b4 = " << b4 << endl;
    answer1 = a4;
    answer2 = b4;
    return 0;
}
