// ======================
// Programmer: 簡睿閎
// Date: 20231113
// File: HW05BR10741071.cpp
// Description: Write a program to simulate the Game of Life for a 20×20 world.
// ======================
#include <iostream>
#include <cmath>
using namespace std;

bool changeState(bool**, int, int);

int answer1; // 儲存第一代的活細胞總數
int answer2; // 儲存第二代的活細胞總數
int answer3; // 儲存第N代的活細胞總數
const int M = 10, N = 9;

int main(void)
{   
    int liveCnt = 0;
    // 紀錄總共會產生幾代
    int numOfGen;
    
    cout << "模擬的世代數 N (5 ≤ N ≤ 20): ";
    cin >> numOfGen;
    
    int lives[numOfGen] = {0};
    
    // 初始世代的活細胞狀態
    bool initial[M][N] = {
        {0},{0},{0},{0,0,0,1,0,1,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0,0},
        {0,0,0,1,0,1,0,0,0},{0},{0},{0}
    };

    // 生成一個初始的雙重指標陣列，並初始化活細胞計數
    bool** current = new bool*[M];
    for (int i = 0; i < M; i++) {
        current[i] = new bool[N]{false};
        for (int j = 0; j < N; j++)
        {
            current[i][j] = initial[i][j];
            liveCnt += current[i][j];
        }
    }
    lives[0] = liveCnt;

    // 生成一個過渡的雙重指標陣列
    bool** transition = new bool*[M];
    for (int i = 0; i < M; i++) 
        transition[i] = new bool[N]{false};
    
    // 模擬世代的變化
    for (int i = 1; i < numOfGen; i++)
    {   
        // 初始活細胞計數
        liveCnt = 0;
        for (int j = 0; j < M; j++)
        {
            for(int k = 0; k < N; k++)
            {
                // 根據規則更新下一代的細胞狀態
                transition[j][k] = changeState(current, j, k)?\
                !current[j][k]:current[j][k];
                liveCnt += transition[j][k];
            }
        }

        // 儲存每一代的活細胞總數
        lives[i] = liveCnt;

        // 切換當前世代和過渡世代
        bool **temp = current;
        current = transition;
        transition = temp;
    }

    // 釋放雙重指標的內存
    for (int i = 0; i < M; ++i) {
        delete[] current[i];
        delete[] transition[i];
    }
    delete[] current;
    delete[] transition;

    // 儲存結果
    answer1 = lives[0];
    answer2 = lives[1];
    answer3 = lives[numOfGen - 1];

    // 輸出結果
    cout << "第一代活細胞數: " << answer1 << endl;
    cout << "第二代活細胞數: " << answer2 << endl;
    cout << "第" << numOfGen << "代活細胞數: " << answer3 << endl;

    return 0;  
}

// 根據遊戲規則判斷細胞是否會變化
bool changeState(bool** current, int row, int col)
{   
    // 檢查鄰居
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    // 鄰居活細胞計數
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        int newX = row + dx[i], newY = col + dy[i];
        // 檢查鄰居在矩陣範圍內
        if (newX >= 0 && newX < M && newY >= 0 && newY < N) 
        {
            cnt += current[newX][newY];
        }
    }

    // 根據遊戲規則判斷是否改變細胞狀態
    if (current[row][col] == 1)
    {
        if (cnt < 2 || cnt > 3)
        {
            return true;
        }
        return false;
    }
    else if (cnt == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
