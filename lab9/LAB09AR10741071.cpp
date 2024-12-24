#include <iostream>
#include <fstream>
#include <cstdlib>   // needed for exit()
#include <string>
using namespace std;
string answer1;      // This variable is for Autolab submission check

int main()
{
    const int STUDENT_NUM = 5;
    string student_name;
    double grade1, grade2, grade3;
    string filename = "grades.dat";  // put the filename up front
    ofstream outfile;

    outfile.open(filename.c_str());  // Check for correctly opening a file
    if (outfile.fail())
    {
        cout << "The file was not successfully opened" << endl;
        exit(1);
    }
    for(int i=0; i < STUDENT_NUM; i++)
    {
        cout << "Please input the student's name and grades: " << endl;
        cin >> student_name >> grade1 >> grade2 >> grade3;
	        // send data to the file
        outfile << student_name << ' ' << grade1 << ' ' << grade2 << ' ' << grade3 << endl;
    }

    answer1 = student_name;     // Store the last student's name for Autolab submission check

    outfile.close();
    cout << "The data has been successfully saved in file " << filename << endl;

    return 0;
}


