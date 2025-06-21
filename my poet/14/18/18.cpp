#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream file("text.txt");

    if (!file) {
        cout << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    char prev = '\0', curr;
    int doubleCount = 0;

    while (file.get(curr)) {
        if (isalpha(curr) && tolower(curr) == tolower(prev)) {
            doubleCount++;
            prev = '\0'; // Пропускаємо наступний, щоб не рахувати перекриття
        } else {
            prev = curr;
        }
    }

    file.close();

    cout << "Кількість подвоєних літер у файлі: " << doubleCount << endl;
    return 0;
}
