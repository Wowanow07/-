#include <iostream>
#include <cstring>   // для strcmp
#include <cstdlib>   // для rand() і srand()
#include <ctime>     // для time()
using namespace std;

// Структура "Товар"
struct Product {
    char name[50];
    double price;
    int quantity;
};

int main() {
    const int N = 5;
    Product products[N] = {
        {"Молоко", 38.50, 120},
        {"Хліб", 25.00, 80},
        {"Сир", 150.75, 45},
        {"Масло", 90.00, 60},
        {"Кава", 250.00, 30}
    };

    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    char searchName[50];
    cout << "Введіть назву товару: ";
    cin.getline(searchName, 50);

    bool found = false;

    for (int i = 0; i < N; ++i) {
        if (strcmp(products[i].name, searchName) == 0) {
            found = true;

            // Генерація знижки від 5% до 30%
            int discountPercent = 5 + rand() % 26; // від 5 до 30
            double discountAmount = products[i].price * discountPercent / 100.0;
            double newPrice = products[i].price - discountAmount;

            // Вивід результату
            cout << "\n🎉 Вітаємо! Ви виграли знижку " << discountPercent << "% на товар \"" << products[i].name << "\"!" << endl;
            cout << "Стара ціна: " << products[i].price << " грн" << endl;
            cout << "Нова ціна: " << newPrice << " грн" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Товар \"" << searchName << "\" не знайдено у базі." << endl;
    }

    return 0;
}
