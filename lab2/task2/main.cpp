#include <iostream>
#include <cmath>

using namespace std;

void fillArray(double* arr, int size, int zeroIndex = 5) {
    for (double* ptr = arr; ptr < (arr + size); ++ptr) {
        *ptr = rand() % 10000 / 100.0;
    }

    *(arr + zeroIndex) = 0.0;
}

void printArray(double* arr, int size) {
    for (double* ptr = arr; ptr < (arr + size); ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;
}

double sumAfterFirstZero(double *arr, int size) {
    double sum = 0;
    bool zeroFound = false;
    for (double* ptr = arr; ptr < (arr + size); ptr++) {
        if (zeroFound) {
            sum += abs(*ptr);
        };
        if (!zeroFound && *ptr == 0) {
            zeroFound = true;
        };
    }
    return sum;
}

int main() {
    srand(time(0));
    const int SIZE = 10;
    const int zeroIndex = rand() % 10;
    double A[SIZE];

    fillArray(A, SIZE, zeroIndex);
    cout << "Массив A: ";
    printArray(A, SIZE);

    cout << "Сумма модулей элементов после первого нуля: " << sumAfterFirstZero(A, SIZE) << endl;

    return 0;
}