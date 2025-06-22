#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double SumHalfSeries(int N) {
    double sum = 0.0;
    double term;
    int i = 0;
    double epsilon = pow(10.0, -N); // точність

    do {
        term = 1.0 / pow(2.0, i);
        sum += term;
        i++;
    } while (term >= epsilon);

    return sum;
}

int main() {
    int N;
    cout << "Введіть кількість знаків після коми (точність): ";
    cin >> N;

    double result = SumHalfSeries(N);
    cout << fixed << setprecision(N);
    cout << "Сума ряду: " << result << endl;

    return 0;
}
