#include <iostream>
#include <string>
using namespace std;

const int KILKIST_DNIV = 7;
const int MAX_SPORTSMENIV = 3;

struct Trenuvannia {
    string prizvyshche;
    string imya;
    int vik;
    double chas[KILKIST_DNIV]; // час тренувань за днями тижня
};

// Назви днів тижня для зручності
string dni_tyzhdnia[KILKIST_DNIV] = {
    "Неділя", "Понеділок", "Вівторок", "Середа", "Четвер", "П’ятниця", "Субота"
};

// Функція для введення часу тренування для певного дня
void VvestyChasZaDen(Trenuvannia tren[], int kilkist) {
    int den;
    cout << "Оберіть день тижня (0 - Неділя, 1 - Понеділок, ..., 6 - Субота): ";
    cin >> den;

    if (den < 0 || den >= KILKIST_DNIV) {
        cout << "Некоректний номер дня.\n";
        return;
    }

    for (int i = 0; i < kilkist; ++i) {
        cout << "Введіть час тренування для спортсмена " 
             << tren[i].prizvyshche << " " << tren[i].imya << ": ";
        cin >> tren[i].chas[den];
    }
}

// Вивід усіх даних
void VyvestyVsiDani(Trenuvannia tren[], int kilkist) {
    cout << "\n=== Таблиця тренувань ===\n";
    for (int i = 0; i < kilkist; ++i) {
        cout << "Спортсмен: " << tren[i].prizvyshche << " " << tren[i].imya << ", Вік: " << tren[i].vik << endl;
        for (int d = 0; d < KILKIST_DNIV; ++d) {
            cout << "  " << dni_tyzhdnia[d] << ": " << tren[i].chas[d] << " год\n";
        }
        cout << endl;
    }
}

int main() {
    Trenuvannia sportmeni[MAX_SPORTSMENIV] = {
        {"Петренко", "Олег", 20, {0}},
        {"Іванова", "Марія", 18, {0}},
        {"Коваленко", "Андрій", 22, {0}}
    };

    char prodovzhyty;

    do {
        VvestyChasZaDen(sportmeni, MAX_SPORTSMENIV);
        cout << "Бажаєте внести дані ще для іншого дня? (т/n): ";
        cin >> prodovzhyty;
    } while (prodovzhyty == 'т' || prodovzhyty == 'Т');

    VyvestyVsiDani(sportmeni, MAX_SPORTSMENIV);

    return 0;
}
