#include <iostream>
#include <string>

using namespace std;

bool isUpper(char C) {
    return (C >= 'A' && C <= 'Z') || (C >= 'А' && C <= 'Я');
    // Кириллица не работает(( Проблемы с кодировкой
    // В UTF8 кириллица кодируется двумя байтами
    // Поэтому g++ считает что это два символа.
    // Использование других кодировок не помогло (CP-1251; KOI8-R)
}

int countUpperLetters (const string &s) {
    int cnt = 0;
    for (char c : s) {
        if (isUpper(c)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string input;

    cout << "Введите строку: ";
    getline(cin, input);

    int count = countUpperLetters(input);
    cout << "Количество заглавных букв: " << count << '\n';

    return 0;
}