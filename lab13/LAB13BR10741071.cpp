#include <iostream>
#include <cmath>
using namespace std;
double answer1, answer2;   // These variables are for Autolab grading

const double PI = 2.0 * asin(1.0);

// declaration section
class Circle
{
    protected:
        double radius;
    public:
        Circle(double = 1.0);  // constructor
        double calcval();
};
// implementation section for Circle
Circle::Circle(double r)   // constructor
{
    radius = r;
}
// calculate the area of a Circle
double Circle::calcval()
{
    return(PI * radius * radius);
}

// declaration section where Cylinder is derived from Circle
class Cylinder : public Circle
{
    protected:
        double length;  // add one data member and
    public:           // two member functions
        Cylinder(double r = 1.0, double l = 1.0) : Circle(r), length(l) {}
        double calcval();
};

// implementation section for Cylinder
double Cylinder::calcval()   // calculates a volume
{
    return (length * Circle::calcval()); // note the base function call
}

int main()
{
    double circle_radius, cylinder_radius, cylinder_length;
    //
    //  Add your code here to complete the program
    cout << "Please input the radius of the circle: ";
    cin >> circle_radius;
    Circle circle_1(circle_radius);

    cout << "Please input the radius of the cylinder: ";
    cin >> cylinder_radius;
    cout << "Please input the length of the cylinder: ";
    cin >> cylinder_length;
    Cylinder cylinder_1(cylinder_radius, cylinder_length);
    //
    answer1 = circle_1.calcval();       // Store the area of the circle for Autolab check
    answer2 = cylinder_1.calcval();     // Store the volume of the cylinder for Autolab check

    cout << "The area of circle is: " << answer1 << endl;
    cout << "The area of cylinder is: " << answer2 << endl;
    return 0;
}

