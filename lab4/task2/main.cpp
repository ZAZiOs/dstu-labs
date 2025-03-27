#include <iostream>
#include <string>

using namespace std;

int countOccurences (const string &s, const string &s0) {
    int cnt = 0;
    size_t pos = s.find(s0);
    // size_t это uint.

    while (pos != string::npos) { // npos значит не найдено. Конец строки
        cnt++;
        pos = s.find(s0, pos + s0.length()); // Сдвигаем 
    }

    return cnt;
}

int main() {
    string s, s0;

    cout << "Введите строку: ";
    getline(cin, s);

    cout << "Введите подстроку: ";
    getline(cin, s0);

    if (s0.empty()) {
        cout << "Подстрока не может быть пустой!";
        return 1;
    }

    int occurences = countOccurences(s, s0);
    cout << "Количество вложений подстроки в строку: " << occurences << endl;

    return 0;
}