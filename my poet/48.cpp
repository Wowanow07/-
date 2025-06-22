#include <iostream>
#include <string>
using namespace std;

// Структура "Бібліотека"
struct Book {
    string title;   // Назва книжки
    string author;  // Автор
    int year;       // Рік видання
    int pages;      // Кількість сторінок
};

int main() {
    const int N = 5;
    Book library[N] = {
        {"Війна і мир", "Лев Толстой", 1869, 1225},
        {"1984", "Джордж Орвелл", 1949, 328},
        {"Убити пересмішника", "Гарпер Лі", 1960, 281},
        {"О дивний новий світ", "Олдос Гакслі", 1932, 268},
        {"Великий Гетсбі", "Френсіс Скотт Фіцджеральд", 1925, 180}
    };

    // Сортування за кількістю сторінок (метод вибору)
    for (int i = 0; i < N - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < N; ++j) {
            if (library[j].pages < library[minIndex].pages) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Book temp = library[i];
            library[i] = library[minIndex];
            library[minIndex] = temp;
        }
    }

    // Вивід результату
    cout << "Список книг за зростанням кількості сторінок:\n";
    for (int i = 0; i < N; ++i) {
        cout << library[i].pages << " стор. — \"" << library[i].title
             << "\" — " << library[i].author << " (" << library[i].year << ")\n";
    }

    return 0;
}
