#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double inputNum(string Name) {
    double num;
    while (true) {
        cout << "Введите " << Name << ": ";
        cin >> num;
        if (cin.fail() || num == 0) {
            cout << "Ошибка ввода. Введено не число.\n";
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
        } else {
            break;
        }
    };
    return num;
}


int main() {
    double x, y;

    x = inputNum("X");

    if (x < -2) {
        cout << "Выполняется условие x < -2\n";
        y = (2 + cos(pow(x, 3) + 3)) / (4 + pow(x, 2)); // 2 + cos(x^3 + 3) | 4 + x^2
    } else if (x < 3) {
        cout << "Выполняется условие -2 <= x < 3\n";
        y = (2 - exp(-2 * x)) / (2 * pow(x, 2) + pow(x, 3)); // 2 - e^(-2x) | 2x^2 + x^3
    } else {
        cout << "Выполняется условие x >= 3\n";
        y = cos(pow(x, 2) + 5 * x) / (5 * pow(x, 2) - 2); // cos(x^2+5x) | 5x^2 - 2
    }

    cout << "Результат вычислений: y = " << y << endl;
    
    return 0;
}