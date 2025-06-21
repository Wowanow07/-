#include <iostream>
using namespace std;

int main() {
    const int N = 8;
    int arr[N] = {9, 4, 7, 2, 6, 3, 1, 5};

    cout << "Початковий масив:\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Сортування методом вибору
    for (int i = 0; i < N - 1; ++i) {
        int minIndex = i;

        // Пошук індексу найменшого елемента в решті масиву
        for (int j = i + 1; j < N; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Обмін поточного елемента з найменшим
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    cout << "Відсортований масив (метод вибору):\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
