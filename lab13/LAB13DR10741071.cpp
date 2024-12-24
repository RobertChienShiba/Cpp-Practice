#include <iostream>
#include <cmath>
using namespace std;
double answer1, answer2, answer3;   // These variables are for Autolab grading

class Rectangle
{
    protected:
        double length, width;
    public:
        Rectangle(double l, double w): length(l), width(w){};
        virtual double area();
};

double Rectangle::area()
{
    return length * width;
}

class Box : public Rectangle
{
    protected:
        double depth;
    public:
        Box(double l, double w, double d): Rectangle(l, w), depth(d){};
        virtual double area();
        double  volume();
};

double Box::area()
{
    return ((length * width) + (length * depth) + (width * depth)) * 2;
}

double Box::volume()
{
    return Rectangle::area() * depth;
}

int main(void)
{
    double rec_length, rec_width;
    double box_length, box_width, box_depth;

    cout << "Please input the length of the rectangle: ";
    cin >> rec_length;

    cout << "Please input the width of the rectangle: ";
    cin >> rec_width;

    Rectangle rectangle(rec_length, rec_width);
    answer1 = rectangle.area();
    cout << "The area of rectangle is: " << answer1 << endl;

    cout << "Please input the length of the box: ";
    cin >> box_length;

    cout << "Please input the width of the box: ";
    cin >> box_width;

    cout << "Please input the depth of the box: ";
    cin >> box_depth;

    Box box(box_length, box_width, box_depth);
    answer2 = box.area();
    answer3 = box.volume();
    cout << "The surface area of box is: " << answer2 << endl;
    cout << "The volume of box is: " << answer3 << endl;
    return 0;
}