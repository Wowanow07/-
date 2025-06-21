#include <iostream>
#include <cmath>
using namespace std;

// Площа правильного п’ятикутника
double Ploshcha(double a) {
    const double pi = 3.141592653589793;
    return (5 * a * a) / (4 * tan(pi / 5));
}

// Площа прямокутника
double Ploshcha(double a, double b) {
    return a * b;
}

// Площа трикутника (формула Герона)
double Ploshcha(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    cout << "Площа п’ятикутника зі стороною 6: " << Ploshcha(6) << endl;
    cout << "Площа прямокутника 5x8: " << Ploshcha(5, 8) << endl;
    cout << "Площа трикутника зі сторонами 3, 4, 5: " << Ploshcha(3, 4, 5) << endl;

    return 0;
}
