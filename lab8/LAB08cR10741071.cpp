#include <iostream>
#include <cstdio>
using namespace std;
char answer1;               // This variable is for Autolab submission check
void encrypt(char* str);
void decrypt(char* str);
int main()
{
    char* str;
    const int STR_SIZE = 10000;
    str = new char [STR_SIZE];
    cout << "Please input a string for encryption: ";
    cin.getline(str, STR_SIZE);
    cout << "The input string is: " << str << endl;

    encrypt( str );
    cout << "Encrypted string is: " << str << endl;
    answer1 = str[0]; // Save the first character of the string after encryption for Autolab 	      	    
    decrypt( str );
    cout << "Decrypted string is: " << str << endl;
    return 0;
}

// encrypt a string
void encrypt( char* str)
{
    while(*str != '\0')
    {
        *str = *str + 1;
        str++;
    }
}

// decrypt a string
void decrypt( char *str )
{
    while(*str != '\0')
    {
        *str = *str - 1;
        str++;
    }
}

