// ======================
// Programmer: 簡睿閎
// Date: 20231020
// File: LAB07DR10741071.cpp
// Description: Write a program to generate an num with 20 elements of random number ranging from 0 to 100.  
// ======================

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

void bubbleSort(int [], int);

int answer1;

int main(void)
{   
    srand(time(nullptr));
    const int inputLen = 20;
    int nums[inputLen] = {0};
    cout << "Before sorting: "; 
    for (int i = 0; i < inputLen; i++)
    {
        nums[i] = rand() % 101;
        cout << nums[i];
        cout << setw(3);
    }
    int size = sizeof(nums) / sizeof(nums[0]);
    bubbleSort(nums, size);
    cout << endl << "After sorting: "; 
    for (int i = 0; i < inputLen; i++)
    {
        cout << nums[i];
        cout << setw(3);
    }
    cout << endl;
    answer1 = nums[inputLen - 1];
    return 0;
}

void bubbleSort(int nums[], int size)
{   
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}
