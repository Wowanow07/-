#include <iostream>
#include <cstring>
using namespace std;

// Оголошення структури
struct Book {
    char title[100];
    char author[100];
    int year;
    int pages;
};

// Функція для обміну двох структур
void swap(Book &a, Book &b) {
    Book temp = a;
    a = b;
    b = temp;
}

int main() {
    setlocale(LC_ALL, "ukr");
    const int N = 5; // Кількість книг
    Book library[N] = {
        {"Майстер і Маргарита", "Булгаков", 1967, 350},
        {"Кобзар", "Шевченко", 1840, 400},
        {"1984", "Оруелл", 1949, 328},
        {"Анна Кареніна", "Толстой", 1877, 864},
        {"Злочин і кара", "Достоєвський", 1866, 430}
    };

    // Сортування за роком видання (зростання) — простий bubble sort
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (library[j].year > library[j + 1].year) {
                swap(library[j], library[j + 1]);
            }
        }
    }

    // Вивід відсортованого масиву
    cout << "Книги у хронологічному порядку:\n";
    for (int i = 0; i < N; ++i) {
        cout << library[i].year << " — \"" << library[i].title
             << "\", автор: " << library[i].author
             << ", сторінок: " << library[i].pages << endl;
    }

    return 0;
}
