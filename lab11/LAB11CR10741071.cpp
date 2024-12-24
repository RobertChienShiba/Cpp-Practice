#include <iostream>
using namespace std;

int answer1, answer2, answer3;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor
    Time() : hour(0), minute(0), second(0) {}

    // Member function to set the time
    void setTime(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
        // Store the values for AUTOLAB Submission Check
        answer1 = h;
        answer2 = m;
        answer3 = s;

    }

    // Member function to print the time
    void printTime() const {
        cout << "The time is: " << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    Time myTime;

    int inputHour, inputMinute, inputSecond;

    // Get input from the user
    cout << "Enter the hour: ";
    cin >> inputHour;

    cout << "Enter the minute: ";
    cin >> inputMinute;

    cout << "Enter the second: ";
    cin >> inputSecond;

    // Set the time using the setTime function
    myTime.setTime(inputHour, inputMinute, inputSecond);

    // Print the time using the printTime function
    myTime.printTime();

    return 0;
}
