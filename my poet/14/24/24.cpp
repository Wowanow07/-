#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const char* filename = "numbers.txt";
    const int COUNT = 20; // Кількість випадкових чисел

    // 1. Створення файлу і запис випадкових чисел
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Помилка створення файлу!" << endl;
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < COUNT; ++i) {
        int num = rand() % 90 + 10; // Випадкове число [10, 99]
        outFile << num << " ";
    }
    outFile.close();

    // 2. Зчитування і обчислення статистики
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Помилка відкриття файлу для читання!" << endl;
        return 1;
    }

    int value, sum = 0, count = 0;
    int minVal = 100, maxVal = 0;

    while (inFile >> value) {
        if (value < minVal) minVal = value;
        if (value > maxVal) maxVal = value;
        sum += value;
        count++;
    }

    inFile.close();

    double average = count > 0 ? static_cast<double>(sum) / count : 0;

    // 3. Дописування результатів у кінець файлу
    ofstream appendFile(filename, ios::app);
    if (!appendFile) {
        cout << "Помилка відкриття файлу для дописування!" << endl;
        return 1;
    }

    appendFile << "\n\n=== Результати ===\n";
    appendFile << "Сума: " << sum << endl;
    appendFile << "Кількість: " << count << endl;
    appendFile << "Середнє: " << average << endl;
    appendFile << "Мінімум: " << minVal << endl;
    appendFile << "Максимум: " << maxVal << endl;

    appendFile.close();

    cout << "Файл '" << filename << "' створено та оновлено!" << endl;
    return 0;
}
