#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Функція для видалення зайвих пробілів з рядка
string VidalytyProbily(const string& line) {
    stringstream ss(line);
    string word;
    string result;
    bool firstWord = true;

    while (ss >> word) { // зчитуємо слова, пропускаючи будь-яку кількість пробілів
        if (!firstWord)
            result += " ";
        result += word;
        firstWord = false;
    }

    return result;
}

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cout << "Не вдається відкрити файл input.txt" << endl;
        return 1;
    }

    ofstream fout("output.txt");
    if (!fout) {
        cout << "Не вдається створити файл output.txt" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        string formatted = VidalytyProbily(line);
        fout << formatted << endl;
    }

    fin.close();
    fout.close();

    cout << "Форматування завершено. Результат у файлі output.txt" << endl;
    return 0;
}
