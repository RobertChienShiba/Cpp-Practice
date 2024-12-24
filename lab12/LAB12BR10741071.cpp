#include <iostream>
#include <cmath>
using namespace std;
double answer1, answer2;   // These variables are for Autolab grading

// declaration section
class Complex
{
    // friends list
    friend double addReal(const Complex&, const Complex&);
    friend double addImag(const Complex&, const Complex&);
    private:
        double realPart;
        double imaginaryPart;
    public:
        Complex(double real = 0.0, double imag = 0.0)  // inline constructor
            {realPart = real; imaginaryPart = imag;}
    void showComplexValues();
    void setComplexValues(double real, double imag); // mutator
    void getComplexValues(double& real, double& imag); // accessor
};

// implementation section
void Complex:: showComplexValues()
{
    char sign = '+';
    if(imaginaryPart < 0) sign = '-';
        cout << realPart << ' ' << sign << ' ' << abs(imaginaryPart) << 'i';
    cout << endl;
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

// friend implementations
//
//   Implement your friend function definition here
//

double addReal(const Complex& a, const Complex& b)
{
    return a.realPart + b.realPart;
}

double addImag(const Complex& a, const Complex& b)
{
    return a.imaginaryPart + b.imaginaryPart;
}

int main()
{
    Complex a, b, c;
    double real_value, imag_value;

    //
    // Write your code here to input and display the two complex numbers
    //

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

    real_value = addReal(a,b);   // sum the real part using friend function
    imag_value = addImag(a,b);   // sum the imaginary part using friend function

    c.setComplexValues(real_value, imag_value);
    cout << "\nThe sum of the first and second complex numbers is: ";
    c.showComplexValues();

    c.getComplexValues(answer1, answer2); // Save the real and imaginary parts of sum for Autolab

    return 0;
}
