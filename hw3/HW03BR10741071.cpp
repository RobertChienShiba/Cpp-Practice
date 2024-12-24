// ======================
// Programmer: 簡睿閎
// Date: 20231017
// File: HW03BR10741071.cpp
// Description: Write, run, and test a C++ program that finds and displays all the isPrime numbers less than 1000.
// ======================

#include <iostream> // 使用cout輸出
#include<cmath> // 使用sqrt函式
using namespace std;

int answer1; // 用於儲存找到的最大質數

int main(void)
{
    for (int i = 1000; i >= 2; i--)
    {
        bool isPrime = true; // 檢查是否為質數
        for (int j = 2; j <= sqrt(i); j++) // 只需要檢查2~sqrt(i)是否有i的因數
        {   
            if (i % j == 0) // j 為 i 的因數，i.e. i為組合數
            {   
                isPrime = false; // i不是質數
                break; // 繼續找下一個i
            }
        }
        if (isPrime) // i是質數
        {
            answer1 = i; // 找到最大質數
            break; // 因為從1000~2找，因此第一個找到就是最大的質數
        }
    }
    // cout << answer1 << endl;
    return 0;
}