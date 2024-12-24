#include <iostream>
using namespace std;

double answer1, answer2;

// declaration section
class Complex
{
    private:
        double realPart;       // declare realPart as a double variable
        double imaginaryPart;  // declare imaginaryPart as a double variable
  
    public:
        Complex(double real = 0.0, double imag = 0.0)    // inline constructor
            {realPart = real; imaginaryPart = imag;}
        void showComplexValues();                        // accessor prototype
        void assignNewValues(double real, double imag)   // inline mutator
            {realPart = real; imaginaryPart = imag;}
        Complex multScaler(double = 1.0);
};   // end of class declaration
// implementation section
void Complex::showComplexValues()   // accessor
{
    char sign = '+';
    if(imaginaryPart < 0) sign = '-';
        cout << "The complex number is " 
            << realPart << ' ' << sign << ' ' << abs(imaginaryPart) << "i\n";
}
Complex Complex::multScaler(double factor)
{
    realPart *= factor;
    imaginaryPart *= factor;
    answer1 = realPart; 
    answer2 = imaginaryPart;
    return Complex (realPart, imaginaryPart);
}
int main()
{
    Complex complexOne(12.57, 18.26), complexTwo;  // declare two objects
    cout << "The value assigned to complexOne is ";
    complexOne.showComplexValues(); 
    complexTwo = complexOne.multScaler(10.0);  // call the function
    cout <<"\nThe value assigned to complexTwo is ";
    complexTwo.showComplexValues(); 
    return 0;
}
