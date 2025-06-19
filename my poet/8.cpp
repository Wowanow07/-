#include <iostream>
#include <cstring>
using namespace std;

// Структура "Країна"
struct Country {
    char name[50];
    char capital[50];
    long population;     // Кількість населення
    double area;         // Площа території в квадратних км
};

int main() {
    const int N = 5;

    Country countries[N] = {
        {"Україна", "Київ", 40000000, 603700},
        {"Японія", "Токіо", 125000000, 377975},
        {"Франція", "Париж", 67000000, 643801},
        {"Індія", "Нью-Делі", 1400000000, 3287263},
        {"Канада", "Оттава", 39000000, 9984670}
    };

    int maxIndex = 0;
    double maxDensity = countries[0].population / countries[0].area;

    for (int i = 1; i < N; ++i) {
        double density = countries[i].population / countries[i].area;
        if (density > maxDensity) {
            maxDensity = density;
            maxIndex = i;
        }
    }

    cout << "Країна з найбільшою густиною населення:\n";
    cout << "Назва: " << countries[maxIndex].name << endl;
    cout << "Столиця: " << countries[maxIndex].capital << endl;
    cout << "Населення: " << countries[maxIndex].population << endl;
    cout << "Площа: " << countries[maxIndex].area << " км²" << endl;
    cout << "Густина населення: " << maxDensity << " осіб/км²" << endl;

    return 0;
}
