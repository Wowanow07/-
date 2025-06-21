#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N] = {4, -3, 5, 2, -1, 7, -6, 8, 0, 1};

    int firstNeg = -1, lastNeg = -1;

    // Знаходимо індекс першого від’ємного
    for (int i = 0; i < N; ++i) {
        if (arr[i] < 0) {
            firstNeg = i;
            break;
        }
    }

    // Знаходимо індекс останнього від’ємного
    for (int i = N - 1; i >= 0; --i) {
        if (arr[i] < 0) {
            lastNeg = i;
            break;
        }
    }

    // Якщо немає 2 від’ємних — нічого не рахуємо
    if (firstNeg == -1 || lastNeg == -1 || firstNeg >= lastNeg) {
        cout << "Недостатньо від’ємних елементів або вони в неправильному порядку." << endl;
        return 0;
    }

    // Обчислюємо суму між ними
    int sum = 0;
    for (int i = firstNeg + 1; i < lastNeg; ++i) {
        sum += arr[i];
    }

    cout << "Сума елементів між першим і останнім від’ємним елементом: " << sum << endl;

    return 0;
}
