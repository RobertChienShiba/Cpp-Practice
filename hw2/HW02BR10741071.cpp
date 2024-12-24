// ======================
// Programmer: 簡睿閎
// Date: 20230929
// File: HW02BR10741071.cpp
// Description:  Write a program that will encrypt data so that it may be transmitted more securely. 
// ======================

#include <iostream> // 為了使用cin、cout
using namespace std; // 使用C++標準函式庫

int answer1, answer2, answer3, answer4, answer5; // Autolab所檢測的global variable

int main(void)
{   
    const int DIGITS = 4; // 固定輸入四位數整數
    int number; // 使用者輸入所賦予的變數
    cin >> number; //使用者輸入

    if (cin.fail()) // 檢查輸入是否為有效數字
    {
        cout << "Invalid input. Please enter a number." << endl; // 告知使用者輸入錯誤訊息
        cin.clear(); // 清除錯誤狀態
        answer5 = 0; // 無效輸入
    }
    else if (number < 1000 || number > 9999) // 檢查輸入是否為四位數
    {
        cout << "Invalid input. it's not a 4-digit integer. Please enter a 4-digits number" << endl; // 告知使用者輸入錯誤訊息
        answer5 = 0; // 無效輸入
    }
    else
    {   
        answer5 = 1; // 有效輸入
        int counter = DIGITS; // 紀錄正在處理第幾位數也代表剩餘多少位數要處理
        int mod, encrypted; // 餘數及該位數加密後的數字
        int total = 0; // 紀錄加密後完整數字
        int temp = number; // 拷貝加密前數字進行運算
        while (temp > 0) // 代表數字還有位數尚未被加密
        {
            mod = temp % 10; // 數字最後一位數
            encrypted = (mod + 7) % 10; // 依題目該位數加密後的數字
            if (counter == 4) // 處理第四位數
            {
                answer3 = encrypted; // 與第三位數進行交換
                total += answer3 * 10; // 轉換成加密後的位數
            }
            else if (counter == 3) // 處理第三位數
            {
                answer4 = encrypted; // 與第四位數進行交換
                total += answer4; // 轉換成加密後的位數
            }
            else if (counter == 2) // 處理第二位數
            {
                answer1 = encrypted; // 與第一位數進行交換
                total += answer1 * 1000; // 轉換成加密後的位數
            }
            else // 處理第一位數
            {
                answer2 = encrypted; // 與第二位數進行交換
                total += answer2 * 100; // 轉換成加密後的位數
            }
            counter -= 1; // 剩餘多少位數要處理
            temp /= 10; // 消除處理完的位數
        }
        cout << total << " is the encrypted integer of " << number << endl; // 符合題目輸出
    } 
    return 0; 
}