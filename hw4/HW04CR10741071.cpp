// ======================
// Programmer: 簡睿閎
// Date: 20231031
// File: HW04CR10741071.cpp
// Description: Write a C++ program that determines student grades at the end of the semester.
// ======================
#include <iostream>
using namespace std;

// 函式宣告，用於冒泡排序和交換學生資料的指標
void bubbleSort(int**);
void swap(int**, int**);

// 存儲計算結果的全域變數
int answer1, answer2;

int main(void)
{
    // 10 位學生的成績資料，包括學號、四次測驗成績及最終加權成績(初始化0)
    int scores[10][6] = {
        {1, 95, 90, 93, 87, 0},
        {2, 100, 95, 91, 85, 0},
        {3, 80, 81, 78, 82, 0},
        {4, 70, 74, 64, 50, 0},
        {5, 98, 77, 95, 90, 0},
        {6, 55, 40, 80, 95, 0},
        {7, 88, 78, 95, 100, 0},
        {8, 66, 78, 65, 60, 0},
        {9, 86, 82, 55, 85, 0},
        {10, 40, 80, 50, 65, 0}
    };

    // 各次測驗成績的權重
    double ratio[4] = {0.2, 0.3, 0.3, 0.2};

    // 指向學生成績的指標陣列
    int* scoresPtr[10] = {nullptr}; 

    // 計算學生最終成績
    for (int i = 0; i < 10; i++)
    {   
        int final = 0;
        for (int j = 1; j < 5; j++)
        {   
            // 計算最終成績
            final += (ratio[j - 1] * scores[i][j]);
        }
        scores[i][5] = final;
        // 將該學生編號及成績放入指標陣列中
        scoresPtr[i] = scores[i];
    }

    // 進行冒泡排序
    bubbleSort(scoresPtr);

    // 輸出排序後的學生成績
    for (int i = 0; i < 10; i++)
    {
        cout << "學生 " << scoresPtr[i][0] << " 最終成績 = " << scoresPtr[i][5] << endl;
    }

    // 存儲計算結果
    answer1 = scoresPtr[0][0]; // 最高分的學號
    answer2 = scoresPtr[9][0]; // 最低分的學號

    return 0;   
}

// 冒泡排序函式，根據最終成績排序學生
void bubbleSort(int** scores) {
    int numRows = 10;
    for (int i = 0; i < numRows - 1; i++) 
    {
        for (int j = 0; j < numRows - i - 1; j++) 
        {   
            // 最終成績比前面高往前交換
            if (scores[j][5] <= scores[j + 1][5]) 
                swap(&(scores[j]), &(scores[j + 1]));
        }
    }
}

// 交換兩個學生資料的指標
void swap(int** std1, int** std2)
{
    int* temp = *std1;
    *std1 = *std2;
    *std2 = temp;
}
