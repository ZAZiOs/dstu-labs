/* план программы:      
1. если длина строки <= 1 - это всегда палиндром
2. на всякий случай если длина строки > 100 - ошибка, дабы рекурсию не портить.
3. если первый и последний символы не равны - это не палиндром
4. идём в подстроку и проверяем что там последний и первый равны, и так до середины.
*/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void inputStr(std::string arr[], int n) {
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cout << "Введите строку " << (i + 1) << ": ";
        getline(cin, arr[i]);  
    }
}


bool Palindrom(const string &S, int left, int right) {
    // строка пуста или 1 символ - true
    if (left >= right) return true;

    // Если слева и справа не равны символы.
    if (S[left] != S[right]) return false;

    // если ничё нет - идём дальше
    return Palindrom(S, left + 1, right - 1);
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int n;
    cout << "Введите количество строк: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Ошибка ввода! Введите натуральное число для количества строк: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    string strings[n];

    cout << "\n---\n\nПРИМЕЧАНИЕ ПЕРЕД ИСПОЛЬЗОВАНИЕМ ВВОДА!\n\nРусские буквы кодируются несколькими байтами, из-за чего нужно использовать тип данных wstring.\nДанная программа НЕ использует wstring, так что русские палиндромы не будут работать как нужно.\nПросьба вводить их транслитом.\n\n---\n\n";
    inputStr(strings, n);

    cout << "\n";

    // Проверяем каждую строку
    for (const string &S : strings) {
        cout << S;
        if (Palindrom(S, 0, S.length() - 1)) {
            cout << " - палиндром.\n";
        } else {
            cout << " - не палиндром.\n";
        }
    }

    return 0;
}