#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int PidrakPodvoien(const string& fileName) {
    ifstream fin(fileName);
    if (!fin) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return -1;
    }

    string line;
    int count = 0;

    while (getline(fin, line)) {
        for (size_t i = 1; i < line.length(); ++i) {
            char prev = tolower(line[i - 1]);
            char curr = tolower(line[i]);
            if (isalpha(prev) && prev == curr)
                count++;
        }
    }

    fin.close();
    return count;
}

int main() {
    string fileName = "input.txt";
    int result = PidrakPodvoien(fileName);

    if (result >= 0)
        cout << "Кількість подвоєних літер: " << result << endl;

    return 0;
}
