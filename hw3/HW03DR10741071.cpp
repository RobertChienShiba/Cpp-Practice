// ======================
// Programmer: 簡睿閎
// Date: 20231017
// File: HW03DR10741071.cpp
// Description: Design a computer program for a person to play Rock-Paper-Scissors game against computer.
// ======================
#include <iostream> // 使用io操作
using namespace std;

const short TERMINATED = 3; // 定義終止遊戲所需的勝利場數
int answer1; // 用於存儲遊戲結果
 
int main(void)
{
    char userChoice, computerChoice; // 用戶和電腦的出拳
    int userWins = 0, computerWins = 0, rounds = 0; // 用戶勝利場數、電腦勝利場數和回合數
    while (userWins != TERMINATED && computerWins != TERMINATED) // 持續猜拳直到產生贏家
    {   
        cout << "Now it's the user's turn: ";
        cin >> userChoice;
        cout << "Now it's the computer's turn: "; 
        cin >> computerChoice;
        if (userChoice == computerChoice) // 出一樣的拳(平手)
        {
            cout << "It's a tie!" << endl;
        } 
        else if ((userChoice == 'R' && computerChoice == 'S') ||
                (userChoice == 'P' && computerChoice == 'R') ||
                (userChoice == 'S' && computerChoice == 'P')) // 用戶勝出
        {   
            cout << "User Choice: (" << userChoice << ") beats Computer Choice: (" << computerChoice << ")" << endl;
            cout << "You win this round!" << endl;
            userWins++; // 用戶勝利場數加一
        } 
        else // 電腦勝出
        {   
            cout << "Computer Choice: (" << userChoice << ") beats User Choice: (" << computerChoice << ")" << endl;
            cout << "Computer wins this round!" << endl;
            computerWins++; // 電腦勝利場數加一
        }
        rounds++; // 猜拳回合數加一
    }
    // 產生贏家
    if (userWins > computerWins) // 用戶是贏家
    {
        cout << "Congratulations! You win the game!" << endl;
    } 
    else // 電腦是贏家
    {
        cout << "Computer wins the game. Better luck next time!" << endl;
    }
    cout << "Total rounds played: " << rounds << endl; // 輸出最終猜拳回合數
    answer1 = rounds; // 用於存儲猜拳結果回合數
    return 0;
}