#include <iostream>
using namespace std;

int Max(int a) {
    return a;
}

int Max(int a, int b) {
    return (a > b) ? a : b;
}

int Max(int a, int b, int c) {
    return Max(Max(a, b), c);
}

int Max(int a, int b, int c, int d) {
    return Max(Max(a, b, c), d);
}

int Max(int a, int b, int c, int d, int e) {
    return Max(Max(a, b, c, d), e);
}

int main() {
    cout << "Max(5) = " << Max(5) << endl;
    cout << "Max(3, 7) = " << Max(3, 7) << endl;
    cout << "Max(4, 2, 9) = " << Max(4, 2, 9) << endl;
    cout << "Max(1, 8, 3, 6) = " << Max(1, 8, 3, 6) << endl;
    cout << "Max(5, 3, 7, 1, 9) = " << Max(5, 3, 7, 1, 9) << endl;
    return 0;
}
