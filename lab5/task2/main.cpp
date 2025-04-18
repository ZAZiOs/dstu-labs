#include <iostream>
#include <cmath>

using namespace std;

double calc(double a, double b) { return sqrt(pow(a, 2) + pow(b, 2) + pow(sin(a * b), 2)); }

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    double x, y, z;

    cout << "Введите значение x: ";
    while (!(cin >> x)) {
        cout << "Ошибка ввода! Введите число для x: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите значение y: ";
    while (!(cin >> y)) {
        cout << "Ошибка ввода! Введите число для y: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите значение z: ";
    while (!(cin >> z)) {
        cout << "Ошибка ввода! Введите число для z: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    double S = calc(x, y) + calc(x, z) + calc(y, z);

    // Вывод результата
    cout << "Результат вычисления S = " << S << endl;

    return 0;
}
