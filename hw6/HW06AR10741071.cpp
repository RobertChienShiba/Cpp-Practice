#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int answer1, answer2, answer3, answer4;

struct Card {
    char suit; // 花色
    int rank;  // 數字
};

const int NUM_PLAYERS = 4;
const int NUM_CARDS = 52;

// 重新洗牌
void shuffleDeck(vector<Card>& deck) {
    random_shuffle(deck.begin(), deck.end());
}

// 依序發牌
void dealCards(vector<Card>& deck, vector<Card> players[NUM_PLAYERS]) {
    int playerIndex = 0;
    for (const auto& card : deck) {
        players[playerIndex].push_back(card);
        playerIndex = (playerIndex + 1) % NUM_PLAYERS;
    }
}

// 是否包含high points
int calculatePoints(const Card& card) {
    if (card.rank == 1) // Ace
        return 4;
    else if (card.rank == 13) // King
        return 3;
    else if (card.rank == 12) // Queen
        return 2;
    else if (card.rank == 11) // Jack
        return 1;
    else
        return 0; // Other cards have 0 points
}

// 計算手牌數值
int calculateTotalPoints(const vector<Card>& hand) {
    int totalPoints = 0;
    for (const auto& card : hand) {
        totalPoints += calculatePoints(card);
    }
    return totalPoints;
}

// 輸出手牌
void printHand(const vector<Card>& hand, int playerIndex) {
    cout << "Player " << playerIndex + 1 << "'s hand: ";
    for (const auto& card : hand) {
        cout << card.rank << card.suit << " ";
    }
    cout << endl;
}

int main(void) {
    // 設定隨機種子
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Card> deck;
    // S: 黑桃 H: 紅心 D: 方塊 C: 梅花
    for (char suit : {'S', 'H', 'D', 'C'}) {
        for (int rank = 1; rank <= 13; ++rank) {
            deck.push_back({suit, rank});
        }
    }

    ofstream outputFile("CardGame.txt");

    // 每個玩家的手牌
    vector<Card> players[NUM_PLAYERS];

    // 紀錄每回合每個玩家手牌high points
    int* points = new int[4];

    // 總共玩3回合
    for (int round = 1; round <= 3; ++round) {
        // 洗牌
        shuffleDeck(deck);

        //發牌
        dealCards(deck, players);

        cout << "Round " << round << " Results:\n";
        outputFile << "Round " << round << " Results:\n";

        // 統計每位玩家手牌
        for (int i = 0; i < NUM_PLAYERS; ++i) {
            printHand(players[i], i);
            points[i] = calculateTotalPoints(players[i]);
            cout << "Total High-card Points: " << points[i] << "\n\n";
            outputFile << "Player " << i + 1 << "'s hand: ";
            for (const auto& card : players[i]) {
                outputFile << card.rank << card.suit << " ";
            }
            outputFile << "\nTotal High-card Points: " << points[i] << "\n\n";
            // 下回合重新發牌
            players[i].clear();
        }
    }
    answer1 = points[0];
    answer2 = points[1];
    answer3 = points[2];
    answer4 = points[3];
    // cout << answer1 << answer2 << answer3 << answer4 << endl;
    // 歸還OS記憶體
    delete[] points;
    return 0;
}