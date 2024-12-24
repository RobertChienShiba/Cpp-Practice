// ======================
// Programmer: 簡睿閎
// Date: 20231020
// File: LAB07CR10741071.cpp
// Description: Write a program that simulates the rolling of two dice. 
// ======================
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int answer1;  
const int PLAYS = 36000; 

int main()
{	
    int die1, die2;
    const int column_size = 6;
    const int row_size = 6;
    int faces[row_size][column_size] = {0};  // initialize the array elements with 0

    for (int i = 0; i < PLAYS; i++)
    {
        die1 = 1 + (rand() % 6);
        die2 = 1 + (rand() % 6);
        faces[die1 - 1][die2 - 1]++;
    }
    for (int i = 0; i < row_size + 1; i++)
    {
        for (int j = 0; j < column_size + 1; j++)
        {   
            if (i == 0 && j == 0)
                cout << " ";
            else if (i == 0 && j > 0)
                cout << j;
            else if (j == 0 && i > 0)
                cout << i;
            else
                cout << faces[i - 1][j - 1];
            cout << "\t";
        }
        cout << endl;
    }
    answer1 = faces[row_size - 1][column_size - 1];
    // cout << answer1 << endl;
    return 0;
}
