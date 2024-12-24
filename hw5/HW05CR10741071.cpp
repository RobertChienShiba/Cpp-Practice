// ======================
// Programmer: 簡睿閎
// Date: 20231113
// File: HW05CR10741071.cpp
// Description: Write a program to solve the rat in a maze puzzle utilizing backtracking algorithm.
// ======================
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int answer1 = INT32_MAX; // 儲存最短路徑的整數值
int answer2 = 0;        // 儲存找到最短路徑所花的總步數
int answer3 = 0;        // 儲存找到最短路徑所花的總向上步數
int answer4 = 0;        // 儲存找到最短路徑所花的總向下步數

const int ROWS = 7;
const int COLS = 7; 
int directionCnt[4] = {0}; // 紀錄搜索過程中向下、右、上、左的步數
int steps = 0; 

void findPath(int[ROWS][COLS], int, int, int);

int main(void)
{   
    // 初始化迷宮
    int maze[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 1, 1},
        {1, 0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0},
        {1, 1, 1, 0, 1, 1, 1},
        {0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 0}
    };
    if(maze[0][0] == 0)
    {   
        // 進入迷宮起點算一步
        steps++;
        findPath(maze, 0, 0, 0);
    }
    else
    {
        answer1 = 0;
    }
    answer2 = steps;
    answer3 = directionCnt[2];
    answer4 = directionCnt[0];

    // 輸出結果
    cout << "最短路徑的整數值: " << answer1 << endl;
    cout << "找到最短路徑所花的總步數: " << answer2 << endl;
    cout << "找到最短路徑所花的總向上步數: " << answer3 << endl;
    cout << "找到最短路徑所花的總向下步數: " << answer4 << endl;

    return 0;
}

void findPath(int maze[ROWS][COLS], int lens, int curR, int curC)
{   
    // 紀錄已經走過的座標
    maze[curR][curC] = 1;
    if(curR == ROWS - 1 && curC == COLS - 1)
    {
        if(lens < answer1)
        {   
            answer1 = lens;
            // 輸出最短路徑的地圖
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                    cout << maze[i][j];
                cout << endl;
            }
        }
        maze[curR][curC] = 0;
        return;
    }

    // 向下移動
    if(curR + 1 < ROWS && maze[curR + 1][curC] == 0)
    {   
        steps++;
        directionCnt[0]++;
        findPath(maze, lens + 1, curR + 1, curC);
    }

    // 向右移動
    if (curC + 1 < COLS && maze[curR][curC + 1] == 0)
    {   
        steps++;
        directionCnt[1]++;
        findPath(maze, lens + 1, curR, curC + 1);
    }

    // 向上移動
    if (curR - 1 >= 0 && maze[curR - 1][curC] == 0)
    {   
        steps++;
        directionCnt[2]++;
        findPath(maze, lens + 1, curR - 1, curC);
    }

    // 向左移動
    if(curC - 1 >= 0 && maze[curR][curC - 1] == 0)
    {   
        steps++;
        directionCnt[3]++;
        findPath(maze, lens + 1, curR, curC - 1);
    }
    // 即將回溯上一個呼叫函式，將座標更改為沒走過
    maze[curR][curC] = 0;
    return;
}
