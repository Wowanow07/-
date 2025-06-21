#include <iostream>
#include <string>
using namespace std;

int BinToDec(string binary) {
    int decimal = 0;
    for (char digit : binary) {
        decimal = decimal * 2 + (digit - '0');
    }
    return decimal;
}

int main() {
    string bin;
    cout << "Введіть двійкове число: ";
    cin >> bin;

    cout << "У десятковій системі: " << BinToDec(bin) << endl;
    return 0;
}
