#include <iostream>
#include <iomanip>
using namespace std;
double answer1, answer2;   // These variables are for Autolab grading

// declaration section
class Complex
{
    private:
        double realPart;        // declare realPart as a double variable
        double imaginaryPart;   // declare imaginaryPart as a double variable
    public:
        Complex(double real = 0.0, double imag = 0.0)    // inline constructor
            {realPart = real; imaginaryPart = imag;}
        void showComplexValues();                        // accessor prototype
        void setComplexValues(double real, double imag); // mutator
        void getComplexValues(double& real, double& imag); // accessor
        Complex operator+(const Complex&);  // prototype for the addition operator
};   // end of class declaration

// implementation section
void Complex::showComplexValues()  // accessor
{
    char sign = '+';
    if(imaginaryPart < 0) sign = '-';
        cout << realPart << ' ' << sign << ' ' << abs(imaginaryPart) << 'i';
}
Complex Complex::operator+(const Complex& complex2)
{
    Complex temp;
    temp.realPart = realPart + complex2.realPart;
    temp.imaginaryPart = imaginaryPart + complex2.imaginaryPart;
    return temp;
}
void Complex::setComplexValues(double real, double imag)  // accessor
{
    realPart = real;
    imaginaryPart = imag;
}
void Complex::getComplexValues(double& real, double& imag)  // accessor
{
    real = realPart;
    imag = imaginaryPart;
}



int main()
{
    Complex a, b, c;  // declare three objects
    double real_value, imag_value;
    
    cout << "Please input the first complex number: ";
    cin >> real_value >> imag_value;
    a.setComplexValues(real_value, imag_value);
    cout << "The first complex number is: ";
    a.showComplexValues();
    cout << endl;

    cout << "Please input the second complex number: ";
    cin >> real_value >> imag_value;
    b.setComplexValues(real_value, imag_value);
    cout << "The second complex number is: ";
    b.showComplexValues();
    cout << endl;

    c = a + b;    // add two complex numbers
    cout << "\nThe sum of the first and second complex number is: ";
    c.showComplexValues();
    c.getComplexValues(answer1, answer2); // Save the real and imaginary parts of sum for Autolab check
    return 0;
}


