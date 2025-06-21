#include <iostream>
using namespace std;

int main() {
    const int N = 8;
    int arr[N] = {5, 2, 9, 1, 5, 6, 3, 7};

    cout << "Початковий масив:\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Сортування методом бульбашки
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмін елементів
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Відсортований масив:\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
