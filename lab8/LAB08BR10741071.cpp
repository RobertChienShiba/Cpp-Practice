#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
int answer1;        // This variable is for Autolab submission check
const int PLAYS = 36000; 
int main()
{
    int die1, die2;
    const int ROW = 6, COL = 6;

    // dynamically create array of pointers of size ROW
    int** matrix_f = new int* [ROW];
    // dynamically allocate memory of size N for each row
    for(int i = 0; i < ROW; i++)
        matrix_f[i] = new int[COL];
    // initialized the allocated memory with 0
    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            matrix_f[i][j] = 0;

    for (int i = 0; i < PLAYS; i++)
    {
        die1 = 1 + (rand() % 6);
        die2 = 1 + (rand() % 6);
        matrix_f[die1 - 1][die2 - 1]++;
    }
    for (int i = 0; i < ROW + 1; i++)
    {
        for (int j = 0; j < COL+ 1; j++)
        {   
            if (i == 0 && j == 0)
                cout << " ";
            else if (i == 0 && j > 0)
                cout << j;
            else if (j == 0 && i > 0)
                cout << i;
            else
                cout << matrix_f[i - 1][j - 1];
            cout << "\t";
        }
        cout << endl;
    }
    answer1 = matrix_f[ROW - 1][COL- 1];
    for (int i = 0; i < ROW; i++) // deallocate memory using delete[] operator
        delete[] matrix_f[i];
    delete[] matrix_f;
    return 0;
}
