// ======================
// Programmer: 簡睿閎
// Date: 20230928
// File: LAB04BR10741071.cpp
// Description: Write a program to print a table of numbers from 1 to 10, including their squares and cubes.
// ======================

#include <iostream>
#include <iomanip>
using namespace std;

double answer1;

int main(void){
    int num;

    cout << "NUMBER\tSQUARE\tCUBE\n"
         << "------\t------\t----\n";

    for (num = 1; num <= 10; num++)
        cout << setw(3) << num << "\t"
        << setw(3) << num * num << "\t"
        << setw(4) << num * num * num << endl;
    answer1 = num;      
    return 0;

}