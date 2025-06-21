#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N] = {5, -2, 7, -1, 9, 0, -6, 4, -3, 8};
    int newSize = N;

    cout << "Початковий масив:\n";
    for (int i = 0; i < newSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Видалення від’ємних елементів зі зміщенням
    for (int i = 0; i < newSize; ) {
        if (arr[i] < 0) {
            // Зміщення всіх елементів лівіше
            for (int j = i; j < newSize - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            --newSize; // зменшуємо розмір масиву
        } else {
            ++i; // переходимо до наступного тільки якщо нічого не видалено
        }
    }

    cout << "Масив після видалення від’ємних елементів:\n";
    for (int i = 0; i < newSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
