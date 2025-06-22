#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Функція підрахунку кількості слів у рядку
int KilkistSliv(const string& line) {
    stringstream ss(line);
    string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    return count;
}

int main() {
    ifstream fin("text.txt");
    if (!fin) {
        cout << "Не вдалося відкрити файл text.txt" << endl;
        return 1;
    }

    string line;
    int totalWords = 0;

    while (getline(fin, line)) {
        totalWords += KilkistSliv(line);
    }

    fin.close();

    cout << "Загальна кількість слів у файлі: " << totalWords << endl;
    return 0;
}
