#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

double answer1;

int main(void)
{
    string filename = "pay.dat";
    string student_name;
    double payRate, hours, regularPay, overtimePay, grossPay; 
    double totalRegular = 0, totalOvertime = 0, totalGross = 0;

    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail())   // check for successful open
    {
        cout << "\nThe file was not successfully opened"
             << "\n Please check that the file currently exists" << endl;
        exit(1);
    }
    cout << left << setw(10) << "Name";
    cout << right << setw(10) << "Pay Rate";
    cout << setw(10) << "Hours";
    cout << setw(15) << "Regular Pay";
    cout << setw(15) << "Overtime Pay";
    cout << setw(15) << "Gross Pay" << endl;
    while (infile >> student_name >> payRate >> hours)
    {   
        regularPay = payRate * min(40.0, hours);
        overtimePay = payRate * 1.5 * max(0.0, hours - 40.0);
        grossPay = regularPay + overtimePay;
        cout << left << setw(10) << student_name;
        cout << right << setw(10) << payRate;
        cout << setw(10) << hours;
        cout << setw(15) << regularPay;
        cout << setw(15) << overtimePay;
        cout << setw(15) << grossPay << endl;
        totalRegular += regularPay;
        totalOvertime += overtimePay;
        totalGross += grossPay;
    }
    cout << "Total Regular pay: " << totalRegular << endl;
    cout << "Total Overtime pay: " << totalOvertime << endl;
    cout << "Total Gross pay: " << totalGross << endl;
    answer1 = totalGross;
    return 0;
}