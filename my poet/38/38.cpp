#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Перевірка: чи слово починається і закінчується на 'А' або 'а'
bool PochynaetsyaIZakinchuietsyaNaA(const string& word) {
    if (word.length() < 2) return false;
    char first = word.front();
    char last = word.back();
    return (first == 'A' || first == 'a' || first == 'А' || first == 'а') &&
           (last  == 'A' || last  == 'a' || last  == 'А' || last  == 'а');
}

// Функція для очищення слова від знаків пунктуації з кінців
string OchyshcheneSlovo(const string& word) {
    int start = 0;
    int end = word.length() - 1;

    while (start <= end && ispunct(word[start])) start++;
    while (end >= start && ispunct(word[end])) end--;

    return word.substr(start, end - start + 1);
}

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cout << "Файл не знайдено!" << endl;
        return 1;
    }

    string word;
    cout << "Слова, що починаються і закінчуються на 'А' або 'а':\n";

    while (fin >> word) {
        string cleaned = OchyshcheneSlovo(word);
        if (PochynaetsyaIZakinchuietsyaNaA(cleaned)) {
            cout << cleaned << endl;
        }
    }

    fin.close();
    return 0;
}
