// ======================
// Programmer: 簡睿閎
// Date: 20230928
// File: LAB04CR10741071.cpp
// Description: Implement a program to compute the average grade for each student in a class of 4 students. 
// ======================

# include <iostream>
#include <iomanip>

using namespace std;
double answer1;

int main(void){
    const int studentNum = 4;
    const int gradeNum = 3;
    double total, average, grade;
    for (int i = 1; i <= studentNum; i++){
        total = 0;
        for (int j = 0; j < gradeNum; j++)
        {
            cout << "Enter an examination of this student: ";
            cin >> grade;
            total += grade;
        }
        average = total / 3;
        cout << "The average for student " << i << " is " << average << endl;
    }
    answer1 = average;
    return 0;
}