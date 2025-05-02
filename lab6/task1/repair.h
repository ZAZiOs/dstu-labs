#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <limits>

using namespace std;

struct Receipt {
    string groupName;
    string model;
    string date;
    bool isCompleted;
};

void addReceipt(vector<Receipt>& receipts);
void printReceipt(const vector<Receipt>& receipts);
void saveToFile(const vector<Receipt>& receipts, const string& filename);
void loadFromFile(vector<Receipt>& receipts, const string& filename);
void searchByGroup(const vector<Receipt>& receipts, const int groupNum);
bool checkFileExist(const string& filename);