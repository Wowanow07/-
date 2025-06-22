#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

// Перевірка, чи символ — голосна літера (англійська)
bool YeHolosna(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    ifstream fin("text.txt");
    if (!fin) {
        cout << "Не вдалося відкрити файл text.txt" << endl;
        return 1;
    }

    char ch;
    int vowels = 0, letters = 0;

    while (fin.get(ch)) {
        if (isalpha(ch)) {
            letters++;
            if (YeHolosna(ch)) {
                vowels++;
            }
        }
    }

    fin.close();

    if (letters == 0) {
        cout << "У тексті немає літер." << endl;
        return 0;
    }

    // Вивід результатів
    cout << "Голосні літери: " << vowels << " з " << letters << " (";
    cout << fixed << setprecision(2) << (100.0 * vowels / letters) << "%)" << endl;

    return 0;
}
