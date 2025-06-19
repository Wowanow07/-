#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N] = {5, 2, 8, 3, 7, 1, 9, 4, 6, 10};

    double sum = 0;

    // Обчислення суми
    for (int i = 0; i < N; ++i) {
        sum += arr[i];
    }

    double average = sum / N;

    cout << "Середнє значення: " << average << endl;
    cout << "Елементи менші за середнє у зворотному порядку:" << endl;

    // Вивід у зворотному порядку
    for (int i = N - 1; i >= 0; --i) {
        if (arr[i] < average) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
    return 0;
}