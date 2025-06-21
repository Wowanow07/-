#include <iostream>
using namespace std;

int main() {
    const int N = 8;
    int arr[N] = {9, 3, 7, 1, 5, 2, 8, 4};

    cout << "Початковий масив:\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Сортування методом вставки
    for (int i = 1; i < N; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Зміщення елементів, які більші за key, праворуч
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "Відсортований масив (метод вставки):\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
