// ======================
// Programmer: 簡睿閎
// Date: 20231113
// File: HW05AR10741071.cpp
// Description: Write a Caesar shift cipher decoder program to decode the following encrypted sentence
// ======================
#include <iostream>
#include <cctype>
using namespace std;

char answer1; // 儲存解碼後句子的第一個字元 
char answer2; // 儲存解碼後句子的最後一個字元

int main(void)
{   
    char string[] = "O RUBK IUSVAZKX VXUMXGSSOTM YU SAIN";
    char* ptr = string;
    const int SHIFT = 6; 
    
    // 透過迴圈遍歷字串中的每個字元
    while (*ptr != '\0') 
    {
        // 檢查字元是否為英文字母
        if(!isspace(*ptr))
        {   
            // 確定基底（大寫字母則為 'A'，小寫字母則為 'a'）
            char base = isupper(*ptr) ? 'A' : 'a';
            
            // 使用凱撒位移密碼解碼字元並更新其值
            *ptr = base + ((*ptr - base - SHIFT + 26) % 26);
        }
        
        // 將目前的字元儲存為解碼後句子的最後一個字元
        answer2 = *ptr;
        
        // 移動到字串中的下一個字元
        ptr++;
    }
    
    // 將解碼後句子的第一個字元儲存
    answer1 = string[0];
    
    // cout << string << endl;
    return 0;
}