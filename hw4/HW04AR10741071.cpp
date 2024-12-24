// ======================
// Programmer: 簡睿閎
// Date: 20231031
// File: HW04AR10741071.cpp
// Description: Write a main program to test your functions with the following sample matrix multiplication.
// ======================
#include <iostream>
using namespace std;

// 存儲計算結果的全域變數
double answer1 = 0;
// 定義A跟B矩陣維度
const int M = 3, L = 4, N = 5;

// 宣告函式
void displayResult(double**);

int main(void) 
{
    // 定義矩陣 A
    double A[3][4] = {
        {5.2, 3.2, 6.8, 8.8}, 
        {3.0, 2.5, 7.7, 6.2},
        {2.7, 7.4, 8.5, 0.5}
    };

    // 定義矩陣 B
    double B[4][5] = {
        {2.1, 1.5, 7.5, 2.6, 5.3},
        {5.2, 2.5, 6.6, 9.2, 7.2},
        {3.6, 8.3, 4.5, 5.4, 2.1},
        {9.3, 4.4, 8.9, 3.5, 0.9}
    };

    // 動態配置二維陣列 C
    double** C;
    C = new double* [M];
    for (int i = 0; i < M; i++)
        C[i] = new double[N]{0};

    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            for (int k = 0; k < L; k++) 
            {   
                // 執行矩陣乘法
                C[i][j] += A[i][k] * B[k][j];
            }
            // 累加C陣列的每個element
            answer1 += C[i][j];
        }
    }

    // 呼叫函數顯示結果
    displayResult(C);

    // 釋放動態配置的記憶體
    for (int i = 0; i < M; i++)
        delete[] C[i];
    delete[] C;

    return 0;
}

void displayResult(double** C) 
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << "元素 C[" << i << "][" << j << "] = " << C[i][j] << endl;
        }
    }
}







