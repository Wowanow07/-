#include <iostream>
#include <cmath> // для sqrt
using namespace std;

// Структура для опису точки на площині
struct Tochka {
    double x;
    double y;
};

// Функція для обчислення довжини відрізка між двома точками
double DovzhynaVidrizka(Tochka a, Tochka b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    Tochka A, B;

    cout << "Введіть координати точки A (x y): ";
    cin >> A.x >> A.y;

    cout << "Введіть координати точки B (x y): ";
    cin >> B.x >> B.y;

    double d = DovzhynaVidrizka(A, B);
    cout << "Довжина відрізка AB = " << d << endl;

    return 0;
}
