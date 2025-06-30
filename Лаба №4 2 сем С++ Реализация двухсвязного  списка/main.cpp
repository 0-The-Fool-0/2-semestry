// main.cpp

#include "header.h"
#include <iostream>
#include <limits>
using namespace std;

// ������� ����������� ����
void displayMenu() {
    cout << "\n����:\n";
    cout << "1. �������� ������� � ������\n";
    cout << "2. �������� ������� � �����\n";
    cout << "3. �������� ������� �� �������\n";
    cout << "4. ������� ������� � ������\n";
    cout << "5. ������� ������� � �����\n";
    cout << "6. ������� ������� �� �������\n";
    cout << "7. ����������� ������\n";
    cout << "8. ������� ������ �� �������\n";
    cout << "9. ��������� ������ � ����\n";
    cout << "10. ��������� ������ �� �����\n";
    cout << "11. �������� ������\n";
    cout << "0. �����\n";
}

// ������� ��� ����������� ����� �����
template <typename T>
T getInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            // �������� ����
            break;
        }
        else {
            // ������������ ����
            cout << "�������� ����. ����������, ���������� �����.\n";
            cin.clear(); // ����� ����� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������������� ����������� �����
        }
    }
    return value;
}

int main() {
    setlocale(LC_ALL, "Russian");
    DoublyLinkedList list;
    int choice;

    do {
        displayMenu();
        choice = getInput<int>("������� ����� ��������: ");

        try {
            switch (choice) {
            case 1: {
                string model = getInput<string>("������� ������: ");
                int year = getInput<int>("������� ��� �������: ");
                double number = getInput<double>("������� �����: ");
                list.addFront(Car(model, year, number));
                cout << "������� �������� � ������.\n";
                break;
            }
            case 2: {
                string model = getInput<string>("������� ������: ");
                int year = getInput<int>("������� ��� �������: ");
                double number = getInput<double>("������� �����: ");
                list.addBack(Car(model, year, number));
                cout << "������� �������� � �����.\n";
                break;
            }
            case 3: {
                string model = getInput<string>("������� ������: ");
                int year = getInput<int>("������� ��� �������: ");
                double number = getInput<double>("������� �����: ");
                size_t index = getInput<size_t>("������� ������: ");
                if (index)
                list.addAt(Car(model, year, number), index-1);
                cout << "������� �������� �� ������� " << index << ".\n";
                break;
            }
            case 4:
                list.removeFront();
                cout << "������� � ������ ������.\n";
                break;
            case 5:
                list.removeBack();
                cout << "������� � ����� ������.\n";
                break;
            case 6: {
                size_t index = getInput<size_t>("������� ������: ");
                list.removeAt(index-1);
                cout << "������� �� ������� " << index << " ������.\n";
                break;
            }
            case 7:
                list.sort();
                cout << "������ ������������.\n";
                break;
            case 8:
                list.printToConsole();
                break;
            case 9: {
                string filename = getInput<string>("������� ��� ����� ��� ����������: ");
                list.printToFile(filename);
                cout << "������ �������� � ���� " << filename << ".\n";
                break;
            }
            case 10: {
                string filename = getInput<string>("������� ��� ����� ��� ��������: ");
                list.loadFromFile(filename);
                cout << "������ �������� �� ����� " << filename << ".\n";
                break;
            }
            case 11: {
                
                list.clear();
                cout << "������ ����" << ".\n";
                break;
            }
            case 0:
                cout << "����� �� ���������.\n";
                break;
            default:
                cout << "�������� �����. ����������, ���������� �����.\n";
            }
        }
        catch (const exception& e) {
            cerr << "������: " << e.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}