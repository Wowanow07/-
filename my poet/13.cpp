#include <iostream>
using namespace std;

int main() {
    const int N = 12;
    int arr[N] = {4, 7, 2, 4, 9, 7, 3, 2, 1, 6, 3, 3};
    bool printed[N] = {false}; // Для запобігання повторному виведенню

    cout << "Повторювані елементи масиву:\n";

    for (int i = 0; i < N; ++i) {
        if (printed[i]) continue; // Якщо вже виводили — пропускаємо

        int count = 1;
        for (int j = i + 1; j < N; ++j) {
            if (arr[i] == arr[j]) {
                count++;
                printed[j] = true; // Позначаємо як уже оброблений
            }
        }

        if (count > 1) {
            cout << arr[i] << " (кількість: " << count << ")\n";
            printed[i] = true;
        }
    }

    return 0;
}
