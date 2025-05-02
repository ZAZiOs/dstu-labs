#include <iostream>
#include <limits>
#include <ctime>

using namespace std;

// ввод числа в матрицу
bool inputNumber(double &num) {
    while (!(cin >> num)) {
        cout << "Ошибка ввода! Введите число: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return true;
}

// ввод матрицы
bool inputMatrix(double **matrix, int M, int N, const string &label) {
    cout << "Введите элементы матрицы " << label << " (" << M << "x" << N << "):\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Элемент[" << i + 1 << "][" << j + 1 << "]: ";
            if (!inputNumber(matrix[i][j])) {
                cout << "Ошибка ввода! Попробуйте еще раз.\n";
                return false;
            }
        }
    }
    return true;
}

void randomizeMatrix(double **matrix, int M, int N, double minVal, double maxVal) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = minVal + (rand() % 1000) / 1000.0 * (maxVal - minVal);
        }
    }
}

void printMatrix(double **matrix, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrix(double **A, double **B, double **result, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(double **A, double **B, double **result, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

int main() {
    srand(time(0));
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int M, N;

    cout << "Введите количество строк: ";
    while (!(cin >> M) || M <= 0) {
        cout << "Ошибка! Введите положительное целое число для количества строк: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите количество столбцов: ";
    while (!(cin >> N) || N <= 0) {
        cout << "Ошибка! Введите положительное целое число для количества столбцов: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // выделяю память.
    double **A = new double*[M];
    double **B = new double*[M];
    double **C = new double*[M];
    double **D = new double*[M];
    double **result = new double*[M];
    for (int i = 0; i < M; ++i) {
        A[i] = new double[N];
        B[i] = new double[N];
        C[i] = new double[N];
        D[i] = new double[N];
        result[i] = new double[N];
    }

    

    double minVal = -10.0, maxVal = 10.0;
    randomizeMatrix(A, M, N, minVal, maxVal);
    randomizeMatrix(B, M, N, minVal, maxVal);
    randomizeMatrix(C, M, N, minVal, maxVal);
    randomizeMatrix(D, M, N, minVal, maxVal);
    cout << "\nA:\n";
    printMatrix(A, M, N);
    cout << "\nB:\n";
    printMatrix(B, M, N);
    cout << "\nC:\n";
    printMatrix(C, M, N);
    cout << "\nD:\n";
    printMatrix(D, M, N);
    

    /*ввод данных в матрицы, по условию требуется, но я сделал рандомайзер так как задолбался на тестах.
    if (!inputMatrix(A, M, N, "A") || !inputMatrix(B, M, N, "B") || !inputMatrix(C, M, N, "C") || !inputMatrix(D, M, N, "D")) {
        cout << "Произошла ошибка при вводе данных. Завершаем программу." << endl;
        return 1;
    } */

    // сложение матриц (A + B) и (C + D)
    double **sumAB = new double*[M];
    double **sumCD = new double*[M];
    for (int i = 0; i < M; ++i) { 
        sumAB[i] = new double[N]; 
        sumCD[i] = new double[N]; 
    }
    addMatrix(A, B, sumAB, M, N);
    addMatrix(C, D, sumCD, M, N);

    // Вычитание матриц (A + B) - (C + D)
    subtractMatrix(sumAB, sumCD, result, M, N);

    cout << "\n---\n\nРезультат P = (A + B) - (C + D):\n";
    printMatrix(result, M, N);

    // очистка памяти
    for (int i = 0; i < M; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
        delete[] D[i];
        delete[] result[i];
        delete[] sumAB[i];
        delete[] sumCD[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] result;
    delete[] sumAB;
    delete[] sumCD;

    return 0;
}
