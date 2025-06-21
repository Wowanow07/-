#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream inFile("text.txt");
    ofstream outFile("text_capitalized.txt");

    if (!inFile || !outFile) {
        cout << "Помилка відкриття файлів!" << endl;
        return 1;
    }

    char ch;
    bool newWord = true;

    while (inFile.get(ch)) {
        if (isalpha(ch)) {
            if (newWord) {
                ch = toupper(ch); // Перша літера слова — велика
                newWord = false;
            } else {
                ch = tolower(ch); // Решта — малі (опціонально)
            }
        } else {
            newWord = true; // Після пробілу або пунктуації — нове слово
        }

        outFile.put(ch);
    }

    inFile.close();
    outFile.close();

    cout << "Файл оброблено. Результат у 'text_capitalized.txt'" << endl;
    return 0;
}
