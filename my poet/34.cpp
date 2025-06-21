#include <iostream>
#include <string>
#include <cstdlib>  // для rand() і srand()
#include <ctime>    // для time()
#include <iomanip>  // для форматування
using namespace std;

const int N = 5; // Кількість товарів

struct Tovar {
    string nazva;
    double tsina;
    int kilkist;
};

// Пошук товару за назвою
int PoshukTovaru(Tovar mas[], int rozmir, const string& nazva) {
    for (int i = 0; i < rozmir; ++i) {
        if (mas[i].nazva == nazva) {
            return i;
        }
    }
    return -1; // не знайдено
}

// Генерація випадкової знижки (від 5% до 30%)
int ZnyzhkaRandom(int min = 5, int max = 30) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(0)); // ініціалізація генератора випадкових чисел

    Tovar sklad[N] = {
        {"Ноутбук", 25000.0, 10},
        {"Смартфон", 15000.0, 20},
        {"Навушники", 1200.0, 50},
        {"Монітор", 7000.0, 15},
        {"Клавіатура", 800.0, 30}
    };

    string zapyt;
    cout << "Введіть назву товару: ";
    getline(cin, zapyt);

    int index = PoshukTovaru(sklad, N, zapyt);

    if (index != -1) {
        double tsina_do = sklad[index].tsina;
        int znyzhka = ZnyzhkaRandom();
        double tsina_pislya = tsina_do * (1 - znyzhka / 100.0);

        cout << fixed << setprecision(2);
        cout << "\n=== Результати Лотереї Знижок ===" << endl;
        cout << "Товар: " << sklad[index].nazva << endl;
        cout << "Ціна до знижки: " << tsina_do << " грн" << endl;
        cout << "Знижка: " << znyzhka << "%" << endl;
        cout << "Ціна після знижки: " << tsina_pislya << " грн" << endl;
    } else {
        cout << "Товар з назвою \"" << zapyt << "\" не знайдено." << endl;
    }

    return 0;
}
