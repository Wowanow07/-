#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

// Перевірка, чи слово починається і закінчується на 'А' або 'а'
bool startsAndEndsWithA(const char* word) {
    int len = strlen(word);
    if (len < 2) return false;

    char first = word[0];
    char last = word[len - 1];

    return (first == 'А' || first == 'а') && (last == 'А' || last == 'а');
}

int main() {
    ifstream file("text.txt");
    if (!file) {
        cout << "Не вдалося відкрити файл." << endl;
        return 1;
    }

    char word[100];
    cout << "Слова, що починаються і закінчуються на 'А' або 'а':\n";

    while (file >> word) {
        // Видаляємо розділові знаки з кінця
        int len = strlen(word);
        while (len > 0 && ispunct(word[len - 1])) {
            word[len - 1] = '\0';
            --len;
        }

        if (startsAndEndsWithA(word)) {
            cout << word << endl;
        }
    }

    file.close();
    return 0;
}
