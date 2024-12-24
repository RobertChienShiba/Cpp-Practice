// ======================
// Programmer: 簡睿閎
// Date: 20230921
// File: LAB03CR10741071.cpp
// Description: a program using a switch statement to select the arithmetic operation.
// ======================

#include <iostream>
using namespace std;

int answer1;
double answer2;

int main(void){
    double nums1, nums2;
    cout << "Please type in two numbers: ";
    cin >> nums1 >> nums2;

    cout << "Enter a select code: ";
    cout << "\n      1  for addition";
    cout << "\n      2  for multiplication";
    cout << "\n      3  for division: ";
    cin >> answer1;
    switch (answer1)
    {
    case 1:
        answer2 = nums1 + nums2;
        cout << "The sum of the numbers entered is " << answer2;
        break;
    case 2:
        answer2 = nums1 * nums2;
        cout << "The product of the numbers entered is " << answer2;
        break;
    case 3:
        answer2 = nums1 / nums2;
        cout << "The first number divided by the second is " << answer2;
        break;
    }
    cout << endl;
    return 0;
}