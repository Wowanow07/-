#include <iostream>
#include <cmath> // для abs
using namespace std;

int SumaCyfr(int n) {
    n = abs(n); // для від’ємних чисел
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

int main() {
    int chislo;
    cout << "Введіть число: ";
    cin >> chislo;

    cout << "Сума цифр числа = " << SumaCyfr(chislo) << endl;

    return 0;
}
