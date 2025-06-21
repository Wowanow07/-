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
        {"War and Peace", "Leo Tolstoy", 1869, 1225},
        {"1984", "George Orwell", 1949, 328},
        {"To Kill a Mockingbird", "Harper Lee", 1960, 281},
        {"Brave New World", "Aldous Huxley", 1932, 268},
        {"The Great Gatsby", "F. Scott Fitzgerald", 1925, 180}
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

    // Вивід відсортованого масиву
    cout << "Список книг у хронологічному порядку:\n";
    for (int i = 0; i < N; ++i) {
        cout << library[i].year << " - \"" << library[i].title
             << "\" by " << library[i].author
             << " (" << library[i].pages << " pages)\n";
    }

    return 0;
}
