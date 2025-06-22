#include <iostream>
using namespace std;

int NSD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return abs(a);
}

int main() {
    int x, y;
    cout << "Введіть два числа: ";
    cin >> x >> y;

    cout << "Найбільший спільний дільник: " << NSD(x, y) << endl;
    return 0;
}
