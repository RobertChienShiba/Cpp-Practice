#include <iostream>
#include <fstream>
#include <cstdlib>   // needed for exit()
#include <string>
using namespace std;

int answer1;

const string targetString = "happy";
const string replacementString= "sad";

int main(void)
{   
    string inputString;
    getline(cin, inputString);
    int pos = 0;
    int count = 0;
    while ((pos = inputString.find(targetString, pos)) < inputString.length())
    {   
        inputString.replace(pos, targetString.length(), replacementString);
        pos += replacementString.length();
        count++;
    }
    cout << count << endl;
    answer1 = count;
    return 0;
}
