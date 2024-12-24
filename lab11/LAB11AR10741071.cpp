#include <iostream>
using namespace std;

double answer1, answer2;

// declaration section
class Complex
{
    private:   // notice the colon after the keyword private
        double realPart;        // data member
        double imaginaryPart;   // data member

    // function prototypes
    public:   // again, notice the colon after the keyword public
        Complex(double = 0.0, double = 0.0);   // member function (constructor)
        void assignNewValues(double, double);  // member function
        void showComplexValues();              // member function
};   // end of class declaration
// implementation section
Complex::Complex(double real, double imag)
{
        realPart = real;
        imaginaryPart = imag;
        answer1 = real;     // for Autolab checking
        answer2 = imag;     // for Autolab checking
}
void Complex::assignNewValues(double real, double imag)
{
    this->realPart = real;
    this->imaginaryPart = imag;

}
void Complex::showComplexValues()
{
    char sign = '+';
    if(imaginaryPart < 0) sign = '-';
        cout << "The complex number is " 
            << this->realPart << ' ' << sign << ' ' << abs(this->imaginaryPart) << "i\n";
}

int main(void)
{
    Complex a, b, c(6.8,9.7);  // declare 3 objects

    // Assign new values to object b's data members
    b.assignNewValues(5.3, -8.4);
    a.showComplexValues();   // display object a's values
    b.showComplexValues();   // display object b's values
    c.showComplexValues();   // display object c's values

    return 0;
}
