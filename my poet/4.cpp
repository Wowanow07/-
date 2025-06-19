#include <iostream>
#include <cmath> // для sqrt та pow
using namespace std;

// Оголошення структури Точка
struct Point {
    double x;
    double y;
};

// Функція для обчислення довжини відрізка між двома точками
double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    Point p1, p2;

    // Введення координат
    cout << "Введіть координати першої точки (x y): ";
    cin >> p1.x >> p1.y;

    cout << "Введіть координати другої точки (x y): ";
    cin >> p2.x >> p2.y;

    double d = distance(p1, p2);

    cout << "Довжина відрізка: " << d << endl;

    return 0;
}
