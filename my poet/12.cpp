#include <iostream>
#include <cstring>
using namespace std;

// Кількість спортсменів
const int NUM_SPORTSMEN = 3;

// Кількість днів тижня
const int DAYS_IN_WEEK = 7;

// Назви днів тижня
const char* weekDays[DAYS_IN_WEEK] = {
    "Понеділок", "Вівторок", "Середа", "Четвер", "П’ятниця", "Субота", "Неділя"
};

// Структура "Тренування"
struct Training {
    char fullName[50];
    int age;
    int minutes[DAYS_IN_WEEK];  // час виконання вправ у хвилинах по днях тижня
};

// Повертає індекс дня тижня або -1, якщо не знайдено
int getDayIndex(const char* inputDay) {
    for (int i = 0; i < DAYS_IN_WEEK; ++i) {
        if (strcmp(inputDay, weekDays[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Training athletes[NUM_SPORTSMEN] = {
        {"Іваненко Петро", 22},
        {"Сидоренко Олена", 19},
        {"Коваль Андрій", 25}
    };

    // Ініціалізація масиву нулями
    for (int i = 0; i < NUM_SPORTSMEN; ++i)
        for (int j = 0; j < DAYS_IN_WEEK; ++j)
            athletes[i].minutes[j] = 0;

    char inputDay[20];
    cout << "Введіть день тижня для заповнення (наприклад, Середа): ";
    cin.getline(inputDay, 20);

    int dayIndex = getDayIndex(inputDay);

    if (dayIndex == -1) {
        cout << "❌ Невірно введено день тижня.\n";
        return 1;
    }

    cout << "\nЗаповніть час виконання вправ для дня \"" << weekDays[dayIndex] << "\"\n";

    for (int i = 0; i < NUM_SPORTSMEN; ++i) {
        cout << athletes[i].fullName << " (вік: " << athletes[i].age << "), хвилин: ";
        cin >> athletes[i].minutes[dayIndex];
    }

    // Виведення для перевірки
    cout << "\n📋 Підсумкова таблиця на день \"" << weekDays[dayIndex] << "\":\n";
    for (int i = 0; i < NUM_SPORTSMEN; ++i) {
        cout << athletes[i].fullName << ": " << athletes[i].minutes[dayIndex] << " хв\n";
    }

    return 0;
}
