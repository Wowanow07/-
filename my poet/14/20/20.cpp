#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

// Перевірка, чи символ — голосна літера (латиниця або українська)
bool isVowel(char ch) {
    ch = tolower(ch);
    // Латинські та українські голосні
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'а' || ch == 'е' || ch == 'и' || ch == 'і' || ch == 'о' || ch == 'у' || ch == 'я' || ch == 'ю' || ch == 'є' || ch == 'ї';
}

int main() {
    ifstream file("text.txt");

    if (!file) {
        cout << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    int totalLetters = 0;
    int totalVowels = 0;
    int vowelsCount[256] = {0};

    char ch;
    while (file.get(ch)) {
        if (isalpha(ch)) {
            totalLetters++;
            if (isVowel(ch)) {
                totalVowels++;
                vowelsCount[tolower(ch)]++;
            }
        }
    }

    file.close();

    cout << "Загальна кількість літер: " << totalLetters << endl;
    cout << "Голосних літер: " << totalVowels << " ("
         << fixed << setprecision(2)
         << (100.0 * totalVowels / totalLetters) << "%)" << endl;

    cout << "\nЧастота голосних по кожній літері:\n";
    for (char c = 'a'; c <= 'z'; ++c) {
        if (vowelsCount[c] > 0) {
            cout << c << ": " << vowelsCount[c]
                 << " (" << fixed << setprecision(2)
                 << (100.0 * vowelsCount[c] / totalLetters) << "%)" << endl;
        }
    }

    // Додатково перевірка українських літер
    const string ukrVowels = "аеёиіоуяює";
    for (char c : ukrVowels) {
        if (vowelsCount[c] > 0) {
            cout << c << ": " << vowelsCount[c]
                 << " (" << fixed << setprecision(2)
                 << (100.0 * vowelsCount[c] / totalLetters) << "%)" << endl;
        }
    }

    return 0;
}
