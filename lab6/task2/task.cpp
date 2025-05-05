#include "task.h"

int getValidatedK() {
    int K;
    while (true) {
        cout << "Введите целое число K (0 < K < 10): ";
        if (cin >> K && K > 0 && K < 10) {
            break;
        } else {
            cout << "Некорректный ввод. Пожалуйста, введите натуральное число от 1 до 9." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return K;
}

vector<string> readLinesFromFile(const string& filename) {
    ifstream inputFile(filename);
    vector<string> lines;
    
    if (!inputFile.is_open()) {
        cout << "Файл " << filename << " не существует или не может быть открыт.";
        exit(1);
    }
    
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
    
    inputFile.close();
    
    if (lines.empty()) {
        cout << "Файл " << filename << " пуст.";
        exit(1);
    }
    
    return lines;
}

void writeTailOutput(const vector<string>& lines, int K, const string& outputFilename) {
    ofstream outputFile(outputFilename);
    
    if (!outputFile.is_open()) {
        cout << "Не удалось создать выходной файл  " << outputFilename;
        exit(1);
    }
    
    // max чтобы минуса не было.
    int startLine = max(0, static_cast<int>(lines.size()) - K);
    for (int i = startLine; i < lines.size(); ++i) {
        outputFile << lines[i] << endl;
    }
    
    outputFile.close();
}