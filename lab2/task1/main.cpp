#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void fillArray(int* arr, int size) {
    for (int* ptr = arr; ptr < (arr + size); ++ptr) {
        *ptr = rand() % 100; // получаем двухзначные числа
    }
}

void copyOddIndexes(int* src, int* dest, int size, int& newSize) {
    newSize = 0;
    for (int* ptr = src; ptr < (src + size); ptr += 2) {
        *(dest + newSize) = *ptr;
        ++newSize;
        /* 
        Я не совсем уверен что это безопасная практика... 
        Можем ли мы случайно попасть на адреса
        со значениями других переменных?
        Наверняка лучше сначала вычислить newSize и
        сделать новый массив.
        */
    }
}

void printArray(int* arr, int size) {
    for (int* ptr = arr; ptr < (arr + size); ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;
}

int inputNum(string Name) {
    int num;
    while (true) {
        cout << "Введите " << Name << " (> 0): ";
        cin >> num;
        if (cin.fail() || num <= 0) {
            cout << "Ошибка ввода. Введено не подходящее число.\n";
            cin.clear();
            cin.ignore(numeric_limits <streamsize> ::max(), '\n');
        } else {
            break;
        }
    };
    return num;
}

int main() {
    srand(time(0));

    int SIZE = /*inputNum("размер массива")*/ 10;
    int A[SIZE], B[SIZE];
    int newSize = 0;

    fillArray(A, SIZE);
    cout << "Массив А: ";
    printArray(A, SIZE);

    copyOddIndexes(A, B, SIZE, newSize);
    cout << "Массив B: ";
    printArray(B, newSize);
    cout << "Размер B: " << newSize << endl;
    return 0;
}