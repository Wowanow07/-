#include <iostream>
using namespace std;

int main() {
    const int N = 8;
    int arr[N] = {10, 20, 30, 40, 50, 60, 70, 80};

    cout << "Оригінальний масив:\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Реверсування масиву
    for (int i = 0; i < N / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[N - 1 - i];
        arr[N - 1 - i] = temp;
    }

    cout << "Реверсований масив:\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
