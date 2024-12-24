#include <iostream>
#include <cmath>
using namespace std;
double answer1, answer2;   // These variables are for Autolab grading
// declaration section for the base class
class One
{
    protected:
        double a;
    public:
        One(double = 2.0);           // constructor
        virtual double f1(double);   // member function
        double f2(double);           // another member function
};
// implementation section for the base class
One::One(double val)   // constructor
{
    a = val;
}
double One::f1(double num)   // member function
{
    return(num/2);
}
double One::f2(double num)   // another member function
{
    return( pow(f1(num),2) );  // square the result of f1()
}


// declaration section for the derived class
class Two : public One
{
    public:
        virtual double f1(double);    // overrides class One's f1()
};

// implementation section for the derived class
double Two::f1(double num)
{
    return(num/3);
}

int main()
{
    One object_1;  // object_1 is an object of the base class
    Two object_2;  // object_2 is an object of the derived class

    answer1 = object_1.f2(12);
    answer2 = object_2.f2(12);
    cout << "base class object call is: "<< answer1 << endl;
    cout << "derive class object call is: "<< answer2 << endl;
    return 0;
}
