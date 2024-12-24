// ======================
// Programmer: 簡睿閎
// Date: 20231017
// File: HW03BR10741071.cpp
// Description: Write a program to display all the pairs of twin prime numbers that are less than 1000.
// ======================

#include <iostream> // 使用cout輸出
#include<cmath> // 使用sqrt函式
using namespace std;

int answer1; // 用於儲存最大pair較小的質數
int answer2; // 用於儲存最大pair較大的質數

int main(void)
{   
    int prevPrime = 2; // 初始化前一個質數為2，從2開始尋找質數pair
    for (int i = 2; i < 1000; i++)
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
            if (i - prevPrime == 2) // 如果相鄰兩個質數差為2，則為質數pair
            {
                answer1 = prevPrime; // 將質數pair中第一個質數存儲在answer1中
                answer2 = i; // 將質數pair中第二個質數存儲在answer2中
                cout << " Pair of twin prime numbers: (" << answer1 <<\
                "," << answer2 << ")" << endl; // 輸出質數pair
            }
            prevPrime = i; // 更新前一個質數為當前數字，繼續尋找下一對質數pair
        }
    }
    return 0;
}