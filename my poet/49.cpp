#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N] = {7, 3, 5, 2, 8, 1, 4, 1, 6, 9};

    int min1 = INT_MAX; // найменший
    int min2 = INT_MAX; // другий найменший

    for (int i = 0; i < N; ++i) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2) {
            min2 = arr[i];
        }
    }

    cout << "Найменший елемент: " << min1 << endl;
    cout << "Другий найменший елемент: " << min2 << endl;

    return 0;
}
