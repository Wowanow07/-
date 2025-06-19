#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N] = {4, -3, 7, 10, -2, 0, 6, -8, 12, 1};

    int sum = 0;

    for (int i = 0; i < N; ++i) {
        if (arr[i] > 0 && arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }

    cout << "Сума парних додатних елементів масиву: " << sum << endl;

    return 0;
}