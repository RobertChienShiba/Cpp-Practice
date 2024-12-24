#include <iostream>
#include <new>
using namespace std;
double answer1;        // This variable is for Autolab submission check
int main()
{
    int numGrades, i;
    double average, total = 0;
    cout << "Enter the number of grades to be processed: ";
    cin  >> numGrades;
    int *grades = new int[numGrades];  // create the array
    for(i = 0; i < numGrades; i++)
    {
        cout << "  Enter a grade: ";
        cin  >> grades[i];
        total = total + grades[i];
    }
    cout << "An array was created for " << numGrades << " integers" << endl;
    cout << "The value stored in the array are: " << endl;
    for (int j = 0; j < numGrades; j++)
    {
        cout << grades[j] << endl;
    }
    average = total / numGrades;
    cout << "The average grade is: " << average << endl;
    answer1 = average; // Save the average for Autolab submission check
    delete[] grades;   // return the storage to the heap
    return 0;
}
