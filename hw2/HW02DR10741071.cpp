// ======================
// Programmer: 簡睿閎
// Date: 20230929
// File: HW02DR10741071.cpp
// Description:  Write a C++ program that accepts three card values as inputs, calculates and display the sum value of the hand, and the sum of the three cards.  
// ======================

#include <iostream> // 為了使用cin、cout
using namespace std; // 使用C++標準函式庫

int answer1, answer2; // Autolab所檢測的global variable

int main(void)
{   
    const int INPUT = 3; // 使用者輸入只有三個
    int num; // 紀錄使用者輸入

    int sum = 0; // 紀錄使用者輸入加總
    int hand = 0; // 紀錄使用者牌面總值
    bool ace = false; // 紀錄牌中是否包含ACE
    for (int i = 0; i < INPUT; i++)
    {   
        cout << "Enter the value of the card (1-13): ";
        cin >> num; // 使用者輸入牌值
        sum += num; // 更新使用者輸入加總
        if (num == 1)
            ace = true; // 紀錄包含ACE
        hand += (num > 10 ? 10 : num); // 處理J、Q、K都算10點
    }
    if (ace == true && hand + 10 <= 21)
        hand += 10; // 若有Ace且加上11不爆牌，則Ace算11點
    answer1 = hand; // 使用者輸入加總
    answer2 = sum; // 使用者牌面總值
    if (answer1 <= 21) 
        cout << "The total value of the hand is " << answer1 << endl; // 沒有爆牌輸入
    else
        cout << "The total value of the hand is " << answer1 << " (bust)." << endl; // 爆牌輸入
    return 0;
}