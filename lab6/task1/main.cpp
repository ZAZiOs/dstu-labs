#include "repair.h"

int main() {
    vector<Receipt> receipts;
    string filename = "receipts.csv";

    string nofilemsg = "Файл необходимый для работы программы не обнаружен. Перезапустите программу и сгенерируйте его ещё раз.\n";

    if (!checkFileExist(filename)) {
        cout << "Перед инициализацией программы в первый раз - нужно заполнить хотя бы одну квитанцию.\n";
        addReceipt(receipts);
        saveToFile(receipts, filename);
    } else {
        loadFromFile(receipts, filename);
    }    


    int choice;
    while (true) {
        cout << "\n--- МЕНЮ ---\n"
             << "1. Добавить квитанцию\n"
             << "2. Проверить квитанции по группе\n"
             << "3. Показать все квитанции\n"
             << "4. Выход\n"
             << "Выберите пункт: ";

        if (!(cin >> choice)) {
            cout << "Неверный ввод!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: // add
                if (!checkFileExist(filename)) {
                    cout << nofilemsg;
                    break;
                }
                cout << "\n";
                receipts.clear();
                loadFromFile(receipts, filename);
                addReceipt(receipts);
                saveToFile(receipts, filename);
                break;
            case 2: // search group
                if (!checkFileExist(filename)) {
                    cout << nofilemsg;
                    break;
                }
                cout << "\n";
                receipts.clear();
                loadFromFile(receipts, filename);
                cin.ignore();
                cout << "Введите номер группы изделий\n1. Телевизоры\n2. Радиоприёмники\n3. Магнитофоны\n";
                int groupNum;
                
                if (!(cin >> groupNum)) {
                    cout << "Неверный ввод! Введите число\n> ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                searchByGroup(receipts, groupNum);
                break;
            case 3: // show all
                if (!checkFileExist(filename)) {
                    cout << nofilemsg;
                    break;
                }
                cout << "\n";
                receipts.clear();
                loadFromFile(receipts, filename);
                printReceipt(receipts);
                break;
            case 4:
                cout << "\n";
                cout << "Выход из программы.\n";
                return 0;
            default:
                break;
        }
    }

    return 0;
}