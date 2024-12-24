// ======================
// Programmer: 簡睿閎
// Date: 20231031
// File: HW04DR10741071.cpp
// Description: Write a C++ program that simulates the casino game of Craps.
// ======================
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 存儲計算結果的全域變數
double answer1, answer2;

// 擲骰子的函數，回傳 2 個骰子的點數總和
int rollDice() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

int main() {
    // 使用時間作為亂數種子，以確保每次遊戲的亂數不同
    srand(time(0));

    int numGames = 10000; // 遊戲次數
    int wins = 0; // 贏的次數
    int totalGameLength = 0; // 所有遊戲的總遊戲長度

    for (int i = 0; i < numGames; i++) {
        int point = 0; // 當前的 "point"，以0初始化
        int gameLength = 0; // 當前遊戲的長度

        while (true) {
            int sum = rollDice(); // 擲骰子
            gameLength++;

            if (gameLength == 1) {
                if (sum == 7 || sum == 11) {
                    wins++; // 玩家贏
                    break;
                } else if (sum == 2 || sum == 3 || sum == 12) {
                    break; // 玩家輸
                } else {
                    point = sum; // 設定 "point"
                }
            } else {
                if (sum == point) {
                    wins++; // 玩家贏
                    break;
                } else if (sum == 7) {
                    break; // 玩家輸
                }
            }
        }

        totalGameLength += gameLength; // 累積遊戲長度
    }

    // 計算贏的機率和平均遊戲長度
    double winProbability = static_cast<double>(wins) / numGames;
    double avgGameLength = static_cast<double>(totalGameLength) / numGames;

    // 輸出結果
    cout << "Craps 遊戲勝利機率: " << winProbability << endl;
    cout << "平均遊戲長度: " << avgGameLength << endl;

    // 存儲計算結果
    answer1 = winProbability;
    answer2 = avgGameLength;

    return 0;
}
