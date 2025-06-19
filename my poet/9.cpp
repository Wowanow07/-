#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N] = {4, -1, -7, 3, -5, 0, -2, 6, -9, 8};

    bool found = false;
    int maxNegative;

    for (int i = 0; i < N; ++i) {
        if (arr[i] < 0) {
            if (!found || arr[i] > maxNegative) {
                maxNegative = arr[i];
                found = true;
            }
        }
    }

    if (found) {
        cout << "Максимальний від’ємний елемент: " << maxNegative << endl;
    } else {
        cout << "У масиві немає від’ємних елементів." << endl;
    }

    return 0;
}
