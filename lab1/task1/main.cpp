#include <iostream>
#include <cmath>
// Если возникнут траблы с кодировкой в терминале - chcp 65001

using namespace std;

int main() {
    double x, y;
    
    cout << "Введите значение x: ";
    cin >> x;
    
    cout << "Введите значение y: ";
    cin >> y;

    if (cin.fail()) {
        cout << "Ошибка ввода! Пожалуйста, введите числа.\n";
        return 1;
    }

    double z = x * sin(y) + sqrt(abs(x * y));

    cout << "Z = " << z << endl;

    return 0;
}
