#include <iostream>
#include <string>
using namespace std;

// Структура "Бібліотека"
struct Book {
    string title;
    string author;
    int year;
    int pages;
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

    // Сортування за роком видання (метод вибору)
    for (int i = 0; i < N - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < N; ++j) {
            if (library[j].year < library[minIndex].year) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Book temp = library[i];
            library[i] = library[minIndex];
            library[minIndex] = temp;
        }
    }

    // Виведення результату
    cout << "Книги у хронологічному порядку:\n";
    for (int i = 0; i < N; ++i) {
        cout << library[i].year << " — \"" << library[i].title
             << "\" — " << library[i].author
             << " (" << library[i].pages << " сторінок)\n";
    }

    return 0;
}
