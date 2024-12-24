// ======================
// Programmer: 簡睿閎
// Date: 20231212
// File: HW07AR10741071.cpp
// Description: Write a C++ program that reads this file and finds the longest word that reverses to a different word. 
// ======================
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int answer1, answer2, answer3;

// 將單字轉換為小寫形式
void toLowercase(string& word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
}

// 讀取檔案並載入單字到 set 中
void loadWords(const string& filename, set<string>& wordSet) {
    ifstream infile(filename);

    if (!infile) {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    string word;
    while (infile >> word) {
        toLowercase(word);
        wordSet.insert(word);
        answer1++;
    }
    infile.close();
}

// 判斷回文
bool isPalindrome(const string& word, string& reversedWord) {
    reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord == word;
}

// 判斷一個單字是否可以反轉為另一個在單字列表中的單字
bool isReversible(const string& word, const set<string>& wordSet, bool& palindrome) {
    string reversedWord = word;
    palindrome = isPalindrome(word, reversedWord);
    return wordSet.find(reversedWord) != wordSet.end();
    // return !palindrome && (wordSet.find(reversedWord) != wordSet.end());
}

// 尋找單字清單中最長的可反轉單字
string findLongestReversibleWord(const set<string>& wordSet) {
    string longestWord;
    bool palindrome;

    for (const string& word : wordSet) {
        if (isReversible(word, wordSet, palindrome)) {
            longestWord = (word.length() > longestWord.length())?word:longestWord;
        }
    }
    return longestWord;
}

// 計算可反轉成對的單字數量
int countReversibleWordPairs(set<string>& wordSet) {
    int cnt = 0;
    int palindromeCnt = 0;
    for (const string& word : wordSet) {
        bool palindrome;
        if (isReversible(word, wordSet, palindrome)){
            if (palindrome)
                palindromeCnt++;
            else
                cnt++;
            // cnt++;
        }
    }
    // 每對單字被計算兩次，所以除以2，回文則只算一組
    return cnt / 2 + palindromeCnt;
}

int main() {
    // 用 set 儲存經過小寫轉換的單字列表
    set<string> wordSet;

    loadWords("words.txt", wordSet);

    // 尋找最長可反轉單字
    string longestReversibleWord = findLongestReversibleWord(wordSet);
    cout << "Longest reversible word: " << longestReversibleWord << endl;
    answer2 = longestReversibleWord.length();

    // 計算可反轉成對的單字數量
    int pairs = countReversibleWordPairs(wordSet);
    cout << "Number of distinct reversible word pairs: " << pairs << endl;
    answer3 = pairs;

    // cout << answer1 << " " << answer2 << " " << answer3 << endl;

    return 0;
}
