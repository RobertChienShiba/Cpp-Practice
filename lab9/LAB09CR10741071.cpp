#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
char answer1;       // This variable is for Autolab submission check
int main()
{
    string filename = "test.dat";
    char ch;
    long offset, last;

    ifstream inFile(filename.c_str());
    if (inFile.fail())   // check for successful open
    {
        cout << "\nThe file was not successfully opened"
             << "\n Please check that the file currently exists" << endl;
        exit(1);
    }
    inFile.seekg(0L,ios::end); // move to the end of the file
    last = inFile.tellg();     // save the offset of the last character

    for(offset = 1L; offset <= last; offset++)
    {
        inFile.seekg(-offset, ios::end);
        ch = inFile.get();
        cout << ch << " : ";
    }
    answer1 = ch;       // Store the first character of the file for Autolab submission check
    inFile.close();
    cout << endl;
    return 0;
}
