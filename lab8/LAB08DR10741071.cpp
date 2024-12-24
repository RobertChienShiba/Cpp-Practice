#include <iostream>
#include <cstdio>
using namespace std;
char answer1;     	// Store the first character of the string after concatenation
int answer2;             // Store the number of characters of the concatenated string str1

void concat_string(char* str1, char* str2);

int main(void)
{
    const int STR_SIZE = 10000;
    char* str1 = new char [2 * STR_SIZE + 1];
    char* str2 = new char[STR_SIZE];
    cout << "Please input the first string: ";
    cin.getline(str1, STR_SIZE);
    cout << "Please input the second string: ";
    cin.getline(str2, STR_SIZE);
    concat_string(str1, str2);
    cout << "After concatenation: ";
    cout << str1 << endl;
    answer1 = *str1;
    cout << "There are " << answer2 << " character in the concatenated string." << endl;
    return 0;
}

void concat_string(char* str1, char* str2)
{
    while(*str1 != '\0')
    {
        str1++;
        answer2++;
    }
    *str1 = ' ';
    str1++;
    answer2++;
    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
        answer2++;
    }
    
}
