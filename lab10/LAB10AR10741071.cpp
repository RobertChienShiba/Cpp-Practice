#include <iostream>
using namespace std;
int answer1, answer2;   // These two variables are for Autolab submission check
int main()
{
    int numerator, denominator;
    bool needDenominator = true;
    cout << "Enter a numerator (whole number only): ";
    cin  >> numerator;
    cout << "Enter a denominator (whole number only): ";
    while(needDenominator)
    {
        cin  >> denominator;
        try
        {
            if (denominator == 0) 
                throw denominator;  // an integer value is thrown
        }
        catch(int e)
        {
            cout << "A denominator value of " << e << " is invalid." << endl;
            cout << "Please re-enter the denominator (whole number only): ";
            continue;  // this sends control back to the while statement
        }    
        cout << numerator <<'/' << denominator << " = " << double(numerator)/ double(denominator) << endl;
        needDenominator = false;
    }
    answer1 = numerator;    // This variables is for Autolab submission check
    answer2 = denominator;  // This variables is for Autolab submission check
    return 0;
}