#include <iostream>
#include <cstring> // для strcmp
using namespace std;

// Структура Перевізник
struct Carrier {
    char departure[50];
    char destination[50];
    int departureTime; // у форматі година*100 + хвилини (наприклад, 8:30 = 830)
    int arrivalTime;
    double price;
};

int main() {
    const int N = 5;

    Carrier routes[N] = {
        {"Київ", "A", 930, 1230, 250.0},
        {"Львів", "B", 800, 1100, 200.0},
        {"Харків", "A", 745, 1045, 300.0},
        {"Одеса", "A", 815, 1115, 270.0},
        {"Дніпро", "C", 900, 1200, 220.0}
    };

    int earliestIndex = -1;

    for (int i = 0; i < N; ++i) {
        if (strcmp(routes[i].destination, "A") == 0) {
            if (earliestIndex == -1 || routes[i].departureTime < routes[earliestIndex].departureTime) {
                earliestIndex = i;
            }
        }
    }

    if (earliestIndex != -1) {
        cout << "Найраніший рейс до пункту призначення 'A':" << endl;
        cout << "Відправлення: " << routes[earliestIndex].departure << endl;
        cout << "Час відправлення: " << routes[earliestIndex].departureTime << endl;
        cout << "Час прибуття: " << routes[earliestIndex].arrivalTime << endl;
        cout << "Вартість: " << routes[earliestIndex].price << " грн" << endl;
    } else {
        cout << "Рейсів до пункту призначення 'A' не знайдено." << endl;
    }

    return 0;
}