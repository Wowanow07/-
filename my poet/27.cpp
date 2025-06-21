#include <iostream>
#include <cmath>
using namespace std;

void VyznachRozriad(int n) {
    if (n == 0) {
        cout << "Кількість розрядів: 1" << endl;
        cout << "Найвищий розряд: 1" << endl;
        return;
    }

    n = abs(n); // від’ємні числа → додатні

    int kilkist = 0;
    int najvysch = 1;
    int temp = n;

    while (temp >= 10) {
        temp /= 10;
        najvysch *= 10;
        kilkist++;
    }
    kilkist++; // додаємо останній розряд

    cout << "Кількість розрядів: " << kilkist << endl;
    cout << "Найвищий розряд: " << najvysch << endl;
}

int main() {
    int number;
    cout << "Введіть число: ";
    cin >> number;

    VyznachRozriad(number);

    return 0;
}
