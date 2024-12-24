// ======================
// Programmer: 簡睿閎
// Date: 20231212
// File: HW07BR10741071.cpp
// Description: Use Object-Oriented Programming approach to design a program for movie rating survey analysis. 
// ======================
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;

int answer1, answer2;  
double answer3;  

class MovieReview {
private:
    string movieTitle;
    double totalScore;
    int numRating;
    double aveScore;

public:
    MovieReview() : totalScore(0), numRating(0), aveScore(0) {}

    // 取得電影標題
    string getMovieTitle() const {
        return movieTitle;
    }

    // 取得總分
    double getTotalScore() const {
        return totalScore;
    }

    // 取得評分數量
    int getNumRating() const {
        return numRating;
    }

    // 取得平均評分
    double getAveScore() const {
        return aveScore;
    }

    // 設定電影標題
    void setMovieTitle(const string& title) {
        movieTitle = title;
    }

    // 設定總分
    void setTotalScore(double score) {
        totalScore = score;
    }

    // 設定評分數量
    void setNumRating(int num) {
        numRating = num;
    }

    // 設定平均評分
    void setAveScore(double ave) {
        aveScore = ave;
    }

    // 新增評分
    void addScore(int score) {
        totalScore += score;
        numRating++;
    }

    // 計算平均評分
    void calculateAveScore() {
        if (numRating > 0) {
            aveScore = totalScore / numRating;
        }
    }
};

// 讀取資料函數
void readData(const string& filename, int& movieSize, MovieReview*& moviesArray) {
    int assumeSize = 20;
    moviesArray = new MovieReview[assumeSize];
    map<string, int> movieMap;  // 使用 map 來記錄電影標題與索引的對應關係

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    string line;
    MovieReview movie;
    while (getline(infile, line)) {
        istringstream iss(line);
        string title;
        int score;

        // 以 '|' 分隔電影標題和評分
        getline(iss, title, '|');
        iss >> score;

        if (movieMap.find(title) != movieMap.end())
        {
            // 若電影已存在，更新評分資訊
            movie = moviesArray[movieMap[title]];
            movie.addScore(score);
            movie.calculateAveScore();
            moviesArray[movieMap[title]] = movie;
        }
        else
        {
            // 若電影不存在，新增電影
            movie = moviesArray[movieSize];
            movie.setMovieTitle(title);
            movie.setTotalScore(score);
            movie.setNumRating(1);
            movieMap[title] = movieSize;
            movie.calculateAveScore();
            moviesArray[movieSize++] = movie;
        }

        // 若陣列大小達到預設值，擴充陣列
        if (movieSize == assumeSize)
        {
            MovieReview* newArray = new MovieReview[movieSize * 2];
            copy(moviesArray, moviesArray + assumeSize, newArray);
            delete[] moviesArray;
            moviesArray = newArray;
            assumeSize = movieSize * 2;
        }
        answer2++;  // 累計處理的評論數
    }
    infile.close();
    answer1 = movieMap.size();  // 總共的電影數
}

// 輸出結果函數
void outputResults(const string& filename, int movieSize,  MovieReview*& moviesArray) {
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    double maxAvg = 0;
    for (int i = 0; i < movieSize; i++) {
        MovieReview movie = moviesArray[i];
        outfile << "Movie Title: " << movie.getMovieTitle() << endl;
        outfile << "Number of Ratings: " << movie.getNumRating() << endl;
        outfile << "Average Rating: " << setprecision(3) << movie.getAveScore() << endl;
        outfile << "--------------------------" << endl;
        maxAvg = (movie.getAveScore() > maxAvg) ? movie.getAveScore() : maxAvg;
    }
    outfile.close();
    answer3 = maxAvg;  // 最高平均評分
}

int main() {
    int movieSize = 0;
    MovieReview* moviesArray = nullptr;
    readData("RatingList.txt", movieSize, moviesArray);
    outputResults("RatingResult.txt", movieSize, moviesArray);
    delete [] moviesArray;  // 釋放動態配置的記憶體
    return 0;
}
