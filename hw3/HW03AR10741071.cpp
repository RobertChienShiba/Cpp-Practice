// ======================
// Programmer: 簡睿閎
// Date: 20231017
// File: HW03AR10741071.cpp
// Description: Write a program to calculate a equation numerically and determine the minimum number of terms required to have an estimation error less than 1.0×10-3.
// ======================
#include <iostream> // 使用cout輸出
#include <cmath> // 使用pow函式
using namespace std;

void calculation(int, double, int, int); // 宣告函式

double answer1;           // 用於存儲滿足誤差要求的最小項數
const double BASE = 2.0;  // 所要逼近的目標值
const double RATIO = 0.5; // 用於計算每一項的比率

int main(void)
{
    calculation(1, 0.0, 0, 0); // 呼叫計算函數，從第一項開始計算
    return 0;
}

void calculation(int n, double sum, int prev1, int prev2)
/*
argument:
n: 目前用了多少項數
sum: 目前累加級數
prev1: Fn-1數值
prev2:  Fn-2數值
*/
{
    double diff = abs(sum - BASE); // 計算當前估計值與目標值的差值

    // 輸出每個n值下的級數值和差值誤差
    cout << "n = " << n - 1 << " 級數值 = " << sum << " 差值誤差 = " << diff << endl;

    if (diff < 1e-3)
    {
        answer1 = n - 1; // 當差值小於1e-3時，存儲最小項數並返回
        return;
    }

    int factor; // 用於紀錄費波那契數列項數值
    if (n == 1)
    {
        factor = 1; // 初始項(F1)
        prev1 = 1;
    }
    else if (n == 2)
    {
        factor = 1; // 初始項(F2)
        prev2 = 1;
    }
    else
    {
        factor = prev1 + prev2; // 根據費波那契數列生成每一項的係數(Fn = Fn-1 + Fn-2)
        prev1 = prev2; // 更新Fn-1
        prev2 = factor; // 更新Fn-2
    }

    calculation(n + 1, sum + (pow(RATIO, n) * factor), prev1, prev2); // 遞歸呼叫計算下一項
    return;
}
