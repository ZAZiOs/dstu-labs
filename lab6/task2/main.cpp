#include "task.h"

int main() {
    setlocale(LC_ALL, "UTF-8");

    int K = getValidatedK();
    
    string inputFilename;
    cout << "Введите имя входного файла (с расширением .txt): ";
    cin >> inputFilename;
    
    vector<string> lines = readLinesFromFile(inputFilename);
    
    string outputFilename = "tail_output.txt";
    
    writeTailOutput(lines, K, outputFilename);
    
    cout << "Последние " << K << " строк были успешно записаны в файл " << outputFilename << endl;
    
    return 0;
}