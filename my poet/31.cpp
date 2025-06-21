#include <iostream>
#include <cmath>
using namespace std;

int MaksymalnaCyfra(int n) {
    n = abs(n);
    int maxCyfra = 0;
    while (n > 0) {
        int cyfra = n % 10;
        if (cyfra > maxCyfra)
            maxCyfra = cyfra;
        n /= 10;
    }
    return maxCyfra;
}

int main() {
    int chislo;
    cout << "Введіть число: ";
    cin >> chislo;

    cout << "Максимальна цифра в числі = " << MaksymalnaCyfra(chislo) << endl;

    return 0;
}
