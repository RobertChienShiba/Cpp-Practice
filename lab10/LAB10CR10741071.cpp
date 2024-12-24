#include <iostream>
#include <fstream>
#include <cstdlib>   // needed for exit()
#include <string>
using namespace std;
int answer1;        // This variable is for Autolab submission check

int main()
{
    ifstream infile;
    string filename = "info.txt";
    string str;
    int i, numChars;
    int vowelCount = 0;

    try  //this block tries to open the input file
    {
        // open a basic input stream
        infile.open(filename.c_str());
        if (infile.fail()) throw filename;
    }   // end of outer try block
    catch (string filename)  // catch for outer try block
    {
        cout << "The input file " << filename
             << " was not successfully opened." << endl
             << " No backup was made." << endl;
        exit(1);
    }
    while(infile.good())
    {
        getline(infile, str);   // use getline() to input the text line by line
        numChars = int(str.length());
        for (i = 0; i < numChars; i++)
        {
            switch(str.at(i))   // here is where a character is retrieved from the string
            {
                case 'a': 
                case 'e': 
                case 'i': 
                case 'o': 
                case 'u':
                vowelCount++;   
            }
        }
    }
    cout << "The input file " << filename << " has " <<  vowelCount <<  " vowels." << endl;
    answer1 = vowelCount;  // Store the number of vowels in the input file for Autolab checking
  
  return 0;
}

