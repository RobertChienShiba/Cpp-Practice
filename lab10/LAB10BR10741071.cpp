#include <iostream>
#include <fstream>
#include <cstdlib>   // needed for exit()
#include <string>
#include <cctype>
using namespace std;
int answer1;         // This variables is for Autolab submission check
int main()
{
    string fileOne = "info.txt";  // put the filename up front
    string fileTwo = "info.bak";
    char ch;  
    ifstream inFile;
    ofstream outfile;
    int count = 0;
    try  //this block tries to open the input file
    {
        // open a basic input stream
        inFile.open(fileOne.c_str());
        if (inFile.fail()) throw fileOne;
    }   // end of outer try block
    catch (string in)  // catch for outer try block
    {
        cout << "The input file " << in
             << " was not successfully opened." << endl
             << " No backup was made." << endl;
        exit(1);
    }

    try  // this block tries to open the output file and
    {    // perform all file processing       

        // open a basic output stream
        outfile.open(fileTwo.c_str());
        if (outfile.fail()) throw fileTwo;
        while (inFile.get(ch))
        {
            count++;
            outfile.put(ch);
        }
    } // end of outer try block
    catch (string out)  // catch for inner try block
    {
        cout << "The backup file " << out 
             << " was not successfully opened." << endl;
        exit(1);    
    }
    // cout << count << endl;
    cout << "A successful backup of " << fileOne 
         << " named " << fileTwo << " was successfully made." << endl;

    answer1 = count;     // Store the number of characters in the file for Autolab submission check

    return 0;
}
