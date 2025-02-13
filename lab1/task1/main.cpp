#include <iostream>
#include <cmath>
// Если возникнут траблы с кодировкой в терминале - chcp 65001

using namespace std;

double inputNum(string Name) {
    double num;
    while (true) {
        cout << "Введите " << Name << ": ";
        cin >> num;
        if (cin.fail()) {
            cout << "Ошибка ввода. Введено не число.\n";
            cin.clear();
            cin.ignore(numeric_limits <streamsize> ::max(), '\n');
        } else {
            break;
        }
    };
    return num;
}

int main() {
    double x, y;
    
    x = inputNum("X");
    y = inputNum("Y");

    double z = x * sin(y) + sqrt(abs(x * y));

    cout << "Z = " << z << endl;

    return 0;
}
