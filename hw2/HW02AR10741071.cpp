// ======================
// Programmer: 簡睿閎
// Date: 20230929
// File: HW02AR10741071.cpp
// Description: Write a program to accept a coordinate point (x, y) in an XY coordinate system and determine in which quadrant or axis the coordinate point lies.
// ======================

#include <iostream> // 為了使用cin、cout
#include <iomanip>  // 為了版面配置setw()
using namespace std; // 使用C++標準函式庫

int answer1; // Autolab所檢測的global variable

int main(void)
{
    double x, y; // 因為座標系統屬於實數範圍，設置double型態
    cin >> x >> y; // 使用者輸入x座標、y座標
    if (x == 0 && y == 0) // 檢查原點
    {
        answer1 = 7;
        cout << "The point (" << x << setw(2) << y << ") is the origin." << endl;
    }
    else if (x == 0) // 檢查是否在x軸上
    {
        answer1 = 6;
        cout << "The point (" << x << setw(2) << y << ") is on the y-axis." << endl;
    }
    else if (y == 0) // 檢查是否在y軸上
    {
        answer1 = 5;
        cout << "The point (" << x << setw(2) << y << ") is on the x-axis." << endl;
    }
    else if (x > 0 && y > 0) // 檢查第一象限範圍
    {
        answer1 = 1;
        cout << "The point (" << x << setw(2) << y << ") is in quadrant I." << endl;
    }
    else if (x < 0 && y > 0) // 檢查第二象限範圍
    {
        answer1 = 2;
        cout << "The point (" << x << setw(2) << y << ") is in quadrant II." << endl;
    }
    else if (x < 0 && y < 0) // 檢查第三象限範圍
    {
        answer1 = 3;
        cout << "The point (" << x << setw(2) << y << ") is in quadrant III." << endl;
    }
    else if (x > 0 && y < 0) // 檢查第四象限範圍
    {
        answer1 = 4;
        cout << "The point (" << x << setw(2) << y << ") is in quadrant IV." << endl;
    }
    return 0;
}