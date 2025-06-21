#include <iostream>
#include <string>
using namespace std;

const int N = 5; // кількість рейсів (можна змінити)

struct Pereviznyk {
    string punkt_vidpravlennia;
    string punkt_pryznachennia;
    int chas_vidpravlennia; // годинник у форматі: 0..23
    int chas_prybuttia;
    double vartist;
};

// Пошук рейсу, що найраніше відправляється до пункту "A"
int ZnaidytyNajrannishyiReis(Pereviznyk mas[], int rozmir) {
    int index = -1;
    int minimal_chas = 24; // максимально можливий час

    for (int i = 0; i < rozmir; i++) {
        if (mas[i].punkt_pryznachennia == "A") {
            if (mas[i].chas_vidpravlennia < minimal_chas) {
                minimal_chas = mas[i].chas_vidpravlennia;
                index = i;
            }
        }
    }

    return index; // -1 якщо немає такого рейсу
}

int main() {
    Pereviznyk marshruty[N] = {
        {"Київ", "A", 12, 14, 300.0},
        {"Львів", "B", 10, 16, 250.0},
        {"Харків", "A", 8, 13, 400.0},
        {"Одеса", "C", 6, 11, 200.0},
        {"Дніпро", "A", 9, 12, 280.0}
    };

    int index = ZnaidytyNajrannishyiReis(marshruty, N);

    if (index != -1) {
        cout << "Найраніший рейс до пункту A:\n";
        cout << "Відправлення: " << marshruty[index].punkt_vidpravlennia << endl;
        cout << "Час: " << marshruty[index].chas_vidpravlennia << ":00" << endl;
        cout << "Вартість: " << marshruty[index].vartist << " грн" << endl;
    } else {
        cout << "Рейсів до пункту A не знайдено.\n";
    }

    return 0;
}
