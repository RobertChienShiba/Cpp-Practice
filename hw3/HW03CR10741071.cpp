// ======================
// Programmer: 簡睿閎
// Date: 20231017
// File: HW03CR10741071.cpp
// Description: Write a C++ program to find how many Lychrel numbers are there below 5,000
// ======================
#include <iostream> // 使用cout輸出
using namespace std;

bool isLychrel(long long);
bool isPalindrome(long long);
long long reverseNum(long long);

int answer1 = 0; // 用於存儲Lychrel數的數量

int main(void)
{
    for (int i = 0; i < 5000; i++) // 尋找1~5000中存在多少Lychrel數
    {
        if (isLychrel(i))
            answer1 += 1; // 如果是Lychrel數，則增加數量
    }
    // cout << answer1 << endl; // 輸出Lychrel數的數量
    return 0;
}

bool isLychrel(long long number)
{   
    long long reverse;
    int counter = 0;
    do
    {
        reverse = reverseNum(number); // 反轉數字
        number += reverse; // 將數字和其反轉相加
        if (isPalindrome(number)) // 如果結果是回文數，則不是Lychrel數
            return false;
        counter++;
    } while (counter < 30); // 迭代 30 次檢查
    return true; // 如果在 30 次迭代內仍未達到回文數，則視為Lychrel數
}

long long reverseNum(long long number)
{
    long long reverse = 0;
    int remainder;
    while (number > 0)
    {
        remainder = number % 10; // 取餘數(最末尾的數字)
        reverse = reverse * 10 + remainder; // 將原本最末尾數字加入反轉數字
        number /= 10; // 移除最末尾數字
    }
    return reverse;
}

bool isPalindrome(long long number)
{
    return number == reverseNum(number); // 檢查是否為回文數
}
