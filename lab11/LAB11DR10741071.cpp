#include <iostream>
#include <cmath>
using namespace std;

double answer1, answer2;

class Pol_coord {
private:
    double dist;
    double theta;

public:
    // Constructor
    Pol_coord() : dist(0.0), theta(0.0) {
        cout << "Initial at r = " << dist << " t = " << theta << endl;
        answer1 = dist;
        answer2 = theta;
    }

    // Display function
    void showData() const {
        cout << "Distance (r): " << dist << ", Theta: " << theta << " degrees" << endl;
    }

    // Mutator function to update data
    void updateData(double newDist, double newTheta) {
        dist = newDist;
        theta = newTheta;
        answer1 = dist;
        answer2 = theta;
    }

    void convToPolar(double x, double y) {
        dist = sqrt(x * x + y * y);
        theta = atan2(y, x) * (180.0 / M_PI);
        updateData(dist, theta);
    }
};

int main(void)
{
    Pol_coord a;

    double x, y, r, t;

    cout << "Enter new distance: ";
    cin >> r;

    cout << "Enter new theta: ";
    cin >> t;

    a.updateData(r, t);

    a.showData();

    cout << "Enter x-coordinate: ";
    cin >> x;

    cout << "Enter y-coordinate: ";
    cin >> y;

    a.convToPolar(x, y);

    a.showData();

    return 0;
}
