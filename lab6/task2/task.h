
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Прототипы функций
int getValidatedK();
vector<string> readLinesFromFile(const string& filename);
void writeTailOutput(const vector<string>& lines, int K, const string& outputFilename);
void processFile();
