#include <iostream>
using namespace std;

unsigned long long Faktorial(int n) {
    if (n < 0) return 0; // факторіал для від’ємних не визначений
    unsigned long long f = 1;
    for (int i = 2; i <= n; ++i) {
        f *= i;
    }
    return f;
}

int main() {
    int num;
    cout << "Введіть число: ";
    cin >> num;

    cout << num << "! = " << Faktorial(num) << endl;

    return 0;
}
