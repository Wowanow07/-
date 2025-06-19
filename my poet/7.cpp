#include <iostream>
#include <cstdlib> // для abs()
using namespace std;

int main() {
    const int N = 6;
    int arr[N] = {12, -305, 7, 40, -18, 99};

    int totalDigitSum = 0;

    for (int i = 0; i < N; ++i) {
        int num = abs(arr[i]); // працюємо з додатним значенням

        // Розкладання на цифри
        while (num > 0) {
            totalDigitSum += num % 10;
            num /= 10;
        }
    }

    cout << "Сума всіх цифр елементів масиву: " << totalDigitSum << endl;

    return 0;
}