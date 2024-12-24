// ======================
// Programmer: 簡睿閎
// Date: 20230928
// File: LAB04ER10741071.cpp
// Description: Write a program that uses a while loop to determine the smallest integer power of 3 that exceeds 30,000.
// ======================

#include <iostream>
#include <iomanip>
using namespace std;

int answer1;

int main(void){
    const int threshold = 3e4;
    int cum = 1;
    int count = 0;
    while (cum <= threshold){
        cum *= 3;
        count += 1;
    }
    answer1 = count;
    cout << "The smallest integer power of 3 that exceeds 30000 is: " << answer1 << endl;
    return 0;
}
