#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer1, answer2, answer3, answer4;

bool PangramCheck(const string& sentence) {
    // 用來儲存每個字母的出現次數
    vector<bool> alphabet(26, false);
    // 剩餘多少字母還沒出現過
    int remaining = 26;

    // 跑過句子中的每個字符
    for (char ch : sentence) {
        if (isalpha(ch)) {
            // 全部轉成小寫
            char lowerCh = tolower(ch);

            if (alphabet[lowerCh - 'a'] == false)
                remaining--;

            // 將出現的字母設為真
            alphabet[lowerCh - 'a'] = true;
        }
    }

    // 檢查是否所有字母都至少出現一次
    return remaining == 0;
}

int main() {
    // 讀取檔案
    ifstream infile("PangramList.txt");
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    int nonPangramCount = 0, pangramCount = 0;
    string longestPangram, shortestPangram;

    int maxLength = 0;
    int minLength = INT32_MAX;

    while (getline(infile, line)) {
        // 檢查是否pangram
        if (!PangramCheck(line)) {
            cout << "Not a pangram: " << line << endl;
            nonPangramCount++;
        } else {
            int length = line.length();

            // 更新最長pangram句子
            if (length > maxLength) {
                maxLength = length;
                longestPangram = line;
            }

            // 更新最短pangram句子
            if (length < minLength) {
                minLength = length;
                shortestPangram = line;
            }
            pangramCount++;
        }
    }

    cout << "Number of non-pangram sentences: " << nonPangramCount << endl;

    // 顯示最長及最短pangram句子
    cout << "Pangram with the longest word: " << longestPangram << endl;
    cout << "Pangram with the shortest word: " << shortestPangram << endl;

    answer1 = nonPangramCount;
    answer2 = pangramCount;
    answer3 = maxLength;
    answer4 = minLength;
    return 0;
}
