// ======================
// Programmer: 簡睿閎
// Date: 20231031
// File: HW04BR10741071.cpp
// Description: Write a C++ program that calls the gcd function repetitively to create a table of greatest common divisor of paired integers from 1 to 20, as the following figure shows.
// ======================
#include <iostream>
#include <iomanip>
using namespace std;

// 存儲計算結果的全域變數
int answer1, answer2, answer3;
// 計算1~20的gcd
const int MAX = 20;
// 輾轉相除法，計算 a 與 b 的最大公因數
int gcd(int, int);

int main(void)
{   
    // 紀錄1~20每對gcd
    int table[MAX][MAX] = {0};
    // 符合期望輸出排版
    cout << setw(7) << "1" << setw(3) << "2" << setw(3) << "3" << setw(3) << "4" << setw(3) <<\
    "5" << setw(3) << "6" << setw(3) << "7" << setw(3) << "8" << setw(3) <<\
    "9" << setw(3) << "10" << setw(3) << "11" << setw(3) << "12" << setw(3) <<\
    "13" << setw(3) << "14" << setw(3) << "15" << setw(3) << "16" << setw(3) <<\
    "17" << setw(3) << "18" << setw(3) << "19" << setw(3) << "20" << setw(3) << endl;
    cout << "=================================================================" << endl;
    cout << setw(3);
    for (int r = 1; r <= MAX; r++)
    {   
        // 符合期望輸出排版
        cout << r << "|  ";
        for (int c = 1; c <= MAX; c++)
        {   
            // 將每對gcd紀錄在相對應的table位置(ex 1&3的gcd會記錄在table[0][2])
            table[r - 1][c - 1] = gcd(r, c);
            cout << table[r - 1][c - 1] << setw(3);
        }
        cout << endl;
    }
    // 存儲計算結果
    answer1 = table[3][15]; // greatest common divisor of 4 and 16
    answer2 = table[2][10]; // greatest common divisor of 3 and 11
    answer3 = table[7][17]; // greatest common divisor of 8 and 18
    return 0;
}

// 輾轉相除法，計算 a 與 b 的最大公因數
int gcd(int a, int b){
    while(b > 0){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}