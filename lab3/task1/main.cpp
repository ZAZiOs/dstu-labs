#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Случайный массив
vector<double> generateArray(int size) {
    vector<double> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 2001 - 1000) / 10.0; // [-100.0; 100.0]
    }
    return arr;
}

void printArray(const vector<double>& arr) {
    for (double num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// считаем нулики
int countZeroElements(const vector<double>& arr) {
    int zeros = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == 0) {
            zeros++;
        }
    }
    return zeros;
}

// найти мин элемент и посчитать
double sumAfterMinElement(const vector<double>& arr) {
    if (arr.empty()) return 0;

    int minIndex = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    double sum = 0;
    for (int i = minIndex + 1; i < arr.size(); i++) {
        sum += arr[i];
    }

    return sum;
}

// sort по возрастанию
void sortByAbsoluteValue(vector<double>& arr) {
    sort(arr.begin(), arr.end(), [](double a, double b) {
        return abs(a) < abs(b);
    });
}

int main() {
    srand(time(0));

    int size;
    cout << "Введите размер массива: ";
    while (!(cin >> size) || size <= 0) {
        cout << "Ошибка! Введите корректный размер массива: ";
        cin.clear();
        cin.ignore(numeric_limits <streamsize> ::max(), '\n');
    }

    vector<double> arr = generateArray(size);

    cout << "Исходный массив: ";
    printArray(arr);

    cout << "Количество элементов, равных 0: " << countZeroElements(arr) << endl;
    cout << "Сумма элементов после минимального элемента: " << sumAfterMinElement(arr) << endl;

    sortByAbsoluteValue(arr);
    cout << "Массив после сортировки по возрастанию модулей элементов: ";
    printArray(arr);

    return 0;
}
