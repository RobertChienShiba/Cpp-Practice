// ======================
// Programmer: 簡睿閎
// Date: 20231020
// File: LAB07BR10741071.cpp
// Description: Write a program to test the function with an integer array of 5 elements. 
// ======================

#include <iostream>
#include <climits>
using namespace std;

int findMax(int [], int);

int answer1;

int main(void)
{
    const int inputLen = 5;
    int nums[inputLen] = {2, 18, 1, 27, 16};
    answer1 = findMax(nums, inputLen);
    cout << "The maximum value is: " << answer1 << endl;
    return 0;
}

int findMax(int nums[], int len)
{   
    int max = -INT32_MAX;
    for (int i = 0; i < len; i++)
        max = nums[i] > max ? nums[i] : max;
    return max;
}