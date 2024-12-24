#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer1 = 0, answer2 = 0;

// 檢查給定字母是否可以組成單字的函數
bool checkWord(const string& dictionaryWord, string myLetters) {
    for (char letter : dictionaryWord) {
        auto pos = myLetters.find(letter);
        if (pos == string::npos) {
            return false; // 沒找到單字
        } else {
            myLetters.erase(pos, 1); // 移除使用過的字母
        }
    }
    return true; // 找到單字
}

// 將有效單字輸出到檔案的函數
void outputValidWords(const vector<string>& validWordList, const string& outFileName) {
    ofstream outFile(outFileName);

    if (!outFile) {
        cerr << "Error: Unable to open output file: " << outFileName << endl;
        return;
    }

    // 按長度降序對單字進行排序
    vector<string> sortedWords = validWordList;
    sort(sortedWords.begin(), sortedWords.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });

    // 輸出到螢幕和文件
    for (const string& word : sortedWords) {
        cout << word << endl;
        outFile << word << endl;
    }

    outFile.close();
}

int main(void) {
    string myLetters;
    cout << "Enter a string of letters: ";
    // 讀取輸入單字
    getline(cin, myLetters);

    ifstream dictionaryFile("Dictionary.txt");
    if (!dictionaryFile) {
        cerr << "Error: Unable to open dictionary file." << endl;
        return 1;
    }

    // 儲存有效單字
    vector<string> validWords;

    string dictionaryWord;
    // 從Dictionary.txt讀取字典單字
    while (dictionaryFile >> dictionaryWord) {
        answer1++;
        // 檢查字典單字是否能由使用者輸入組成
        if (checkWord(dictionaryWord, myLetters)) {
            answer2++;
            validWords.push_back(dictionaryWord);
        }
        // cout << myLetters << endl;
    }

    dictionaryFile.close();

    if (validWords.empty()) {
        cout << "No valid words found." << endl;
    } else {
        outputValidWords(validWords, "ValidWords.txt");
        cout << "Valid words saved to ValidWords.txt." << endl;
    }
    // cout << answer1 << " " << answer2 << endl;
    return 0;
}
