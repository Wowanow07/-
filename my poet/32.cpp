#include <iostream>
#include <string>
using namespace std;

const int N = 5; // кількість країн

struct Krayina {
    string nazva;
    string stolitsya;
    double naselennya; // у мільйонах
    double ploshcha;   // у тис. км²
};

// Знаходження країни з найбільшою густиною населення
int KrayinaZMaxGustynoyu(Krayina mas[], int rozmir) {
    int index = 0;
    double maxGustyna = mas[0].naselennya / mas[0].ploshcha;

    for (int i = 1; i < rozmir; i++) {
        double gustyna = mas[i].naselennya / mas[i].ploshcha;
        if (gustyna > maxGustyna) {
            maxGustyna = gustyna;
            index = i;
        }
    }

    return index;
}

int main() {
    Krayina svit[N] = {
        {"Україна", "Київ", 41.0, 603.7},
        {"Китай", "Пекін", 1440.0, 9597.0},
        {"Індія", "Нью-Делі", 1393.0, 3287.0},
        {"США", "Вашингтон", 331.0, 9834.0},
        {"Бангладеш", "Дакка", 165.0, 147.6}
    };

    int index = KrayinaZMaxGustynoyu(svit, N);

    cout << "Країна з найбільшою густиною населення:\n";
    cout << "Назва: " << svit[index].nazva << endl;
    cout << "Столиця: " << svit[index].stolitsya << endl;
    cout << "Населення: " << svit[index].naselennya << " млн" << endl;
    cout << "Площа: " << svit[index].ploshcha << " тис. км²" << endl;
    cout << "Густина: " << svit[index].naselennya / svit[index].ploshcha << " осіб/км²" << endl;

    return 0;
}
