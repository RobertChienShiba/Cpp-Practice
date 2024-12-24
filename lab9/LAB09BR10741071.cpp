#include <iostream>
#include <fstream>
#include <cstdlib>   // needed for exit()
#include <string>
#include <iomanip>   // needed for setprecision
using namespace std;
double answer1;      // This variable is for Autolab submission check
int main()
{
    string student_name;
    double grade1, grade2, grade3, average;
    string filename = "grades.dat";  // put the filename up front
    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail())               // Check for correctly opening a file
    {
        cout << "The file was not successfully opened" << endl;
        exit(1);
    }
    while(infile >> student_name >> grade1 >> grade2 >> grade3)
    {
        average = (grade1 + grade2 + grade3) / 3;
        cout << "The average grade is: " << setprecision(3) << average << endl;
    }
    answer1 = average;      // Store the average grade of the last student for Autolab submission check
    infile.close();
    return 0;
}
