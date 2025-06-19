#include <iostream>
using namespace std;

int main() {
    const int N = 12;
    int arr[N] = {3, 5, 3, 7, 5, 3, 2, 5, 5, 7, 8, 5};

    int maxCount = 0;
    int mostFrequent = arr[0];

    for (int i = 0; i < N; ++i) {
        int count = 0;

        // Підрахунок кількості входжень arr[i]
        for (int j = 0; j < N; ++j) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        // Оновлення максимуму
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    cout << "Найчастіше зустрічається число: " << mostFrequent << endl;
    cout << "Кількість повторень: " << maxCount << endl;

    return 0;
}
