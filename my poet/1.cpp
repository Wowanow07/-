#include <iostream>
using namespace std;

int main() {
    const int N = 10; // розмір масиву
    int arr[N] = {5, 2, 8, 2, 3, 7, 1, 9, 1, 4};

    // Початкові значення - встановимо перші два елементи правильно
    int min1, min2;

    if (arr[0] < arr[1]) {
        min1 = arr[0];
        min2 = arr[1];
    } else {
        min1 = arr[1];
        min2 = arr[0];
    }

    for (int i = 2; i < N; ++i) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2) {
            min2 = arr[i];
        }
    }

    cout << "Два найменших елементи: " << min1 << " і " << min2 << endl;

    return 0;
}