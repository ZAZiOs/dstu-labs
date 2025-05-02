#include "repair.h"

void addReceipt(vector<Receipt>& receipts) {
    Receipt r;

    cout << "Введите номер группы изделий\n1. Телевизоры\n2. Радиоприёмники\n3. Магнитофоны\n";
    int _1stInput;
    bool _1stInputDone = false;
    while (!_1stInputDone) {
        cout << "> ";

        // если не инт
        if (!(cin >> _1stInput)) {
            cout << "Неверный ввод, попробуйте ещё раз.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // если всё таки инт, но нужно ж проверить что оно подходит в список.
        else {
            switch (_1stInput) {
                case 1:
                    r.groupName = "Телевизоры";
                    _1stInputDone = true;
                    break;
                case 2:
                    r.groupName = "Радиоприёмники";
                    _1stInputDone = true;
                    break;
                case 3:
                    r.groupName = "Магнитофоны";
                    _1stInputDone = true;
                    break;
                default: 
                    cout << "Неверный ввод!\n";
                    break;
            };
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Введите марку изделия: ";
    getline(cin, r.model);

    cout << "Введите дату приёмки (например, 2025.05.01): ";
    getline(cin, r.date);

    cout << "Состояние готовности (1 — выполнен, 0 — не выполнен)\n> ";
    int status;
    while (!(cin >> status) || (status != 0 && status != 1)) {
        cout << "Неверный ввод, 1 или 0\n> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    r.isCompleted = status;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    receipts.push_back(r);
    cout << "Квитанция добавлена!\n";
}

void printReceipt(const vector<Receipt>& receipts) {
    for (const auto& r : receipts) {
        cout << "Группа: " << r.groupName << "\n"
             << "Модель: " << r.model << "\n"
             << "Дата: " << r.date << "\n"
             << "Статус: " << (r.isCompleted ? "Выполнен" : "Не выполнен") << "\n\n";
    }
}

void saveToFile(const vector<Receipt>& receipts, const string& filename) {
    ofstream out(filename);
    for (const auto& r : receipts) {
        out << r.groupName << ";" << r.model << ";" << r.date << ";" << r.isCompleted << "\n";
    }
    out.close();
}

void loadFromFile(vector<Receipt>& receipts, const string& filename) {
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        Receipt r;
        size_t pos1 = line.find(';');
        size_t pos2 = line.find(';', pos1 + 1);
        size_t pos3 = line.find(';', pos2 + 1);

        r.groupName = line.substr(0, pos1);
        r.model = line.substr(pos1 + 1, pos2 - pos1 - 1);
        r.date = line.substr(pos2 + 1, pos3 - pos2 - 1);
        r.isCompleted = stoi(line.substr(pos3 + 1));
        receipts.push_back(r);
    }
    in.close();
}

void searchByGroup(const vector<Receipt>& receipts, const int groupNum) {
    bool found = false;

    vector<string> AllowedGroups = {
        "Телевизоры", "Радиоприёмники", "Магнитофоны"
    };

    // Эту строчку для цикла мне подсказал GPT. Оч крутая вещь, мне понравилось, я похожую в JS обычно использую.
    for (const auto& r : receipts) {
        if (r.groupName == AllowedGroups[groupNum - 1]) {
            cout << "Модель: " << r.model << "\nДата: " << r.date
                 << "\nСтатус: " << (r.isCompleted ? "Выполнен" : "Не выполнен") << "\n\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Нет заказов по заданной группе.\n";
    }
}

bool checkFileExist(const string& filename) {
    ifstream file(filename);
    return file && file.peek() != ifstream::traits_type::eof();
}
