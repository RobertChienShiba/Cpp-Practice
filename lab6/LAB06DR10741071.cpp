// ======================
// Programmer: 簡睿閎
// Date: 20231012
// File: LAB06DR10741071.cpp
// Description: Write a program to find the maximum number and total number of palindromic numbers below 1e4.
// ======================

#include <iostream>
using namespace std;

bool isPalindrome(int);
int reverseDigit(int);
int answer1, answer2;

int main(void)
{
    const int BOUND = 1e4;
    int count = 0;
    cout << "Please specify the number below which is wish to find the maximum palindrome: "\
    << BOUND << endl;
    for (int i = 0; i <= BOUND; i++)
    {
        if (isPalindrome(i))
        {
            answer1 = i;
            count += 1;
        }
    }
    answer2 = count;
    cout << "The maximum palindrome number below " << BOUND << " is " << answer1 << endl;
    cout << "The total number of palindrome number below " << BOUND << " is " << answer2 << endl;
    return 0;
    
}

bool isPalindrome(int num)
{
    if (num == reverseDigit(num))
        return true;
    return false;
}

int reverseDigit(int num)
{   
    int reverse = 0;
    int mod;
    while (num != 0)
    {
        mod = num % 10;
        reverse = reverse * 10 + mod;
        num /= 10;
    }
    return reverse;
}