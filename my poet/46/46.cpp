#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

// Генерація випадкових чисел і запис у файл
void CreateFileWithRandomNumbers(const string& filename, int count) {
    ofstream fout(filename);
    if (!fout) {
        cout << "Не вдалося створити файл!" << endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < count; ++i) {
        int number = 10 + rand() % 90; // число від 10 до 99
        fout << number << " ";
    }

    fout << endl;
    fout.close();
}

// Зчитування, обчислення статистики і дописування у файл
void AnalyzeAndAppend(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Не вдалося відкрити файл!" << endl;
        return;
    }

    int num, sum = 0, count = 0;
    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();

    while (fin >> num) {
        sum += num;
        count++;
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }
    fin.close();

    if (count == 0) {
        cout << "Файл не містить чисел." << endl;
        return;
    }

    double average = static_cast<double>(sum) / count;

    ofstream fout(filename, ios::app); // відкриваємо для дописування
    fout << "\nMin: " << minVal;
    fout << "\nMax: " << maxVal;
    fout << "\nAverage: " << average << endl;
    fout.close();

    cout << "Аналіз завершено. Дані дописано у файл." << endl;
}

int main() {
    string filename = "numbers.txt";

    CreateFileWithRandomNumbers(filename, 20); // 20 випадкових чисел
    AnalyzeAndAppend(filename);

    return 0;
}
