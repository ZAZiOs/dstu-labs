#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y;

    cout << "Введите X: ";
    cin >> x;

    if (cin.fail()) {
        cout << "Ошибка ввода. Введено не число.\n";
        return 1;
    }

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

    cout << "Результат вычислений: y = " << y;
    
    return 0;
}