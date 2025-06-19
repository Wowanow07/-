#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Функція для очищення рядка від зайвих пробілів
string cleanSpaces(const string& line) {
    stringstream input(line);
    string word, result;
    while (input >> word) {
        if (!result.empty())
            result += " ";
        result += word;
    }
    return result;
}

int main() {
    ifstream inFile("text.txt");
    ofstream outFile("text_cleaned.txt");

    if (!inFile || !outFile) {
        cout << "Помилка відкриття файлів!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        string cleaned = cleanSpaces(line);
        if (!cleaned.empty())
            outFile << cleaned << endl;
    }

    inFile.close();
    outFile.close();

    cout << "Файл успішно очищено і збережено як 'text_cleaned.txt'" << endl;
    return 0;
}
