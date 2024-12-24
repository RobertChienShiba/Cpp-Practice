#include <iostream>
#include <cmath>
using namespace std;
int answer1, answer2;   // These variables are for Autolab grading

class Complex
{
    private:
        int numPart;
        int denomPart;
    public:
        Complex(int num = 1.0, int denom = 1.0)  // inline constructor
            {numPart = num; denomPart = denom;}
    void showComplexValues();
    void showComplexValues(char arithmetic);
    void setComplexValues(int num, int denom); // mutator
    void getComplexValues(int& num, int& denom); // accessor
    friend Complex operator+(Complex const& c1, Complex const& c2);
    friend Complex operator-(Complex const& c1, Complex const& c2);
    friend Complex operator*(Complex const& c1, Complex const& c2);
    friend Complex operator/(Complex const& c1, Complex const& c2);
};

void Complex::showComplexValues(char arithmetic)
{   
    bool sameSign = ((numPart ^ denomPart) < 0) ? 0 : 1;
    numPart = (sameSign) ? abs(numPart) : numPart;
    denomPart = (sameSign) ? abs(denomPart) : denomPart;
    switch (arithmetic)
    {
    case '+':
        cout << "a" << arithmetic << "b = " << numPart << '/' << denomPart; 
        break;
    case '-':
        cout << "a" << arithmetic << "b = " << numPart << '/' << denomPart; 
        break;
    case '*':
        cout << "a" << arithmetic << "b = " << numPart << '/' << denomPart; 
        break;  
    case '/':
        cout << "a" << arithmetic << "b = " << numPart << '/' << denomPart; 
        break;    
    }
    cout << endl;
    // cout << "Fraction is: " << numPart << '/' << denomPart << endl;
}

void Complex::showComplexValues()
{   
    bool sameSign = ((numPart ^ denomPart) < 0) ? 0 : 1;
    numPart = (sameSign) ? abs(numPart) : numPart;
    denomPart = (sameSign) ? abs(denomPart) : denomPart;
    cout << "Fraction is: " << numPart << '/' << denomPart << endl;
}

void Complex::setComplexValues(int num, int denom)
{
    numPart = num;
    denomPart = denom;
}

void Complex::getComplexValues(int& num, int& denom)
{
    num = numPart;
    denom = denomPart;
}

Complex operator+(const Complex& complex1, const Complex& complex2)
{   
    int a = complex1.numPart;
    int b = complex1.denomPart;
    int c = complex2.numPart;
    int d = complex2.denomPart;
    return Complex(a * d + b * c, b * d);
}

Complex operator-(const Complex& complex1, const Complex& complex2)
{   
    int a = complex1.numPart;
    int b = complex1.denomPart;
    int c = complex2.numPart;
    int d = complex2.denomPart;
    return Complex(a * d - b * c, b * d);
}

Complex operator*(const Complex& complex1, const Complex& complex2)
{   
    int a = complex1.numPart;
    int b = complex1.denomPart;
    int c = complex2.numPart;
    int d = complex2.denomPart;
    return Complex(a * c, b * d);
}

Complex operator/(const Complex& complex1, const Complex& complex2)
{   
    int a = complex1.numPart;
    int b = complex1.denomPart;
    int c = complex2.numPart;
    int d = complex2.denomPart;
    return Complex(a * d , b * c);
}

int main(void)
{
    int num1, denom1;
    cout << "Please input the first fraction (numerator denominator): ";
    cin >> num1 >> denom1;

     Complex c1;
     c1.setComplexValues(num1, denom1);
     c1.showComplexValues();

    int num2, denom2;
    cout << "Please input the second fraction (numerator denominator): ";
    cin >> num2 >> denom2;

     Complex c2;
     c2.setComplexValues(num2, denom2);
     c2.showComplexValues();

    Complex c3;
    c3 = c1 + c2;
    c3.showComplexValues('+');
    c3 = c1 - c2;
    c3.showComplexValues('-');
    c3 = c1 * c2;
    c3.showComplexValues('*');
    c3 = c1 / c2;
    c3.showComplexValues('/');
    c3.getComplexValues(answer1, answer2);

    return 0;
}