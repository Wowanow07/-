#include <iostream>
#include <string>
using namespace std;

string DecToHex(int n) {
    if (n == 0) return "0";
    string hex = "";
    char hexChars[] = {'0','1','2','3','4','5','6','7','8','9',
                       'A','B','C','D','E','F'};
    while (n > 0) {
        int r = n % 16;
        hex = hexChars[r] + hex;
        n /= 16;
    }
    return hex;
}

int main() {
    int num;
    cout << "Введіть десяткове число: ";
    cin >> num;

    cout << "Шістнадцяткове число: " << DecToHex(num) << endl;

    return 0;
}
