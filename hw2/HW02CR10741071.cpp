// ======================
// Programmer: 簡睿閎
// Date: 20230929
// File: HW02CR10741071.cpp
// Description:  Write a C++ program that computes the singing contest average score of a singer. 
// ======================

#include <iostream> // 為了使用cin、cout
#include <iomanip> // 為了使用浮點數精簡在後二位
using namespace std; // 使用C++標準函式庫

double answer1; // Autolab所檢測的global variable


int main(void)
{   
    const int JUDGES = 4; // 固定有四個評分系統
    double num1, num2, num3, num4; // 儲存四個評分系統分別給的分數
    cin >> num1 >> num2 >> num3 >> num4; // 使用者輸入評分

    bool valid = true; // 紀錄使用者輸入是否有效    
    for (int i = 1; i <= JUDGES; i++)
    {
        if (i == 1 && num1 <= 10 && num1 >= 0) // 檢查輸入一是否有效
            num1 = num1;
        else if (i == 2 && num2 <= 10 && num2 >= 0) // 檢查輸入二是否有效
        {   
            /* 如果輸入二比輸入一小，互換兩者數值，目的是將最小的輸入保持在變數一*/
            if (num2 < num1) 
            {
                double temp = num2; // 暫存變數二
                num2 = num1; // 變數交換
                num1 = temp; // 變數交換
            }
        }
        else if (i == 3 && num3 <= 10 && num3 >= 0) // 檢查輸入三是否有效
        {   
            /* 如果輸入三比輸入一小，互換兩者數值，目的是將最小的輸入保持在變數一*/
            if (num3 < num1)
            {
                double temp = num3; // 暫存變數三
                num3 = num1; // 變數交換
                num1 = temp; // 變數交換
            }
        }
        else if (i == 4 && num4 <= 10 && num4 >= 0) // 檢查輸入三是否有效
        {   
            /* 如果輸入四比輸入一小，互換兩者數值，目的是將最小的輸入保持在變數一*/
            if (num4 < num1)
            {
                double temp = num4; // 暫存變數四
                num4 = num1; // 變數交換
                num1 = temp; // 變數交換
            }
        }
        else // 無效輸入
        {
            valid = false; // 無效輸入
            break; // 因為無效輸入中止使用者繼續輸入
        }
    }
    if (valid == true) // 有效輸入
    {   
        answer1 = (num2 + num3 + num4) / 3; // 紀錄撇除最低評分的平均分數
        cout << "The final score of the singer is " << setprecision(3) << answer1 << endl; // 控制輸出平均分數在小數點後兩位
    }
    else 
    { 
        answer1 = -1.0; // 無效輸入
        cout << "Erroneous JUDGES!" << endl; // 輸出無效輸入訊息
    }
    return 0;
}