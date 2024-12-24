#include <iostream>
#include <iomanip>
using namespace std;
long answer1;             // This variable is for Autolab grading

// declaration section
class Date
{
    private:
    int month, day, year;
    public:
        Date(int = 7, int = 4, int = 2012);    // constructor
        operator long();  // conversion operator prototype
        void showDate();
};

// implementation section
Date::Date(int mm, int dd, int yyyy) // constructor
{
    month = mm;
    day = dd;
    year = yyyy;
}
// conversion operator definition for converting a Date to a long int
Date::operator long()   // must return a long, as its name implies
{
    long yyyymmdd;
    yyyymmdd = year * 10000 + month * 100 + day;
    return(yyyymmdd);
}
// member function to display a date
void Date::showDate()
{
    cout << setfill('0')
         << setw(2) << month << '/' << setw(2) << day << '/' << setw(2) << year % 100;
    return;
}

int main()
{
    int day, month, year;
    long b;            // declare an object of type long

    cout << "Please enter the day: ";
    cin >> day;
    cout << "Please enter the month: ";
    cin >> month;
    cout << "Please enter the year: ";
    cin >> year;

    Date a(day, month, year);
    cout << "a's date is ";
    a.showDate();

    b = a;       // call the conversion function
    cout << "\nThis date, as a long integer, is " << b << endl;
    answer1 = b;       // Save the long integer for Autolab check
    
    return 0;
}
