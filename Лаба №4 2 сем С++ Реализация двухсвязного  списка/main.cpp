// main.cpp

#include "header.h"
#include <iostream>
#include <limits>
using namespace std;

// Функция отображения меню
void displayMenu() {
    cout << "\nМеню:\n";
    cout << "1. Добавить элемент в начало\n";
    cout << "2. Добавить элемент в конец\n";
    cout << "3. Добавить элемент по индексу\n";
    cout << "4. Удалить элемент в начале\n";
    cout << "5. Удалить элемент в конце\n";
    cout << "6. Удалить элемент по индексу\n";
    cout << "7. Сортировать список\n";
    cout << "8. Вывести список на консоль\n";
    cout << "9. Сохранить список в файл\n";
    cout << "10. Загрузить список из файла\n";
    cout << "11. Очистить список\n";
    cout << "0. Выход\n";
}

// Функция для безопасного ввода числа
template <typename T>
T getInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            // Успешный ввод
            break;
        }
        else {
            // Некорректный ввод
            cout << "Неверный ввод. Пожалуйста, попробуйте снова.\n";
            cin.clear(); // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирование оставшегося ввода
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
        choice = getInput<int>("Введите номер операции: ");

        try {
            switch (choice) {
            case 1: {
                string model = getInput<string>("Введите модель: ");
                int year = getInput<int>("Введите год выпуска: ");
                double number = getInput<double>("Введите номер: ");
                list.addFront(Car(model, year, number));
                cout << "Элемент добавлен в начало.\n";
                break;
            }
            case 2: {
                string model = getInput<string>("Введите модель: ");
                int year = getInput<int>("Введите год выпуска: ");
                double number = getInput<double>("Введите номер: ");
                list.addBack(Car(model, year, number));
                cout << "Элемент добавлен в конец.\n";
                break;
            }
            case 3: {
                string model = getInput<string>("Введите модель: ");
                int year = getInput<int>("Введите год выпуска: ");
                double number = getInput<double>("Введите номер: ");
                size_t index = getInput<size_t>("Введите индекс: ");
                if (index)
                list.addAt(Car(model, year, number), index-1);
                cout << "Элемент добавлен по индексу " << index << ".\n";
                break;
            }
            case 4:
                list.removeFront();
                cout << "Элемент в начале удален.\n";
                break;
            case 5:
                list.removeBack();
                cout << "Элемент в конце удален.\n";
                break;
            case 6: {
                size_t index = getInput<size_t>("Введите индекс: ");
                list.removeAt(index-1);
                cout << "Элемент по индексу " << index << " удален.\n";
                break;
            }
            case 7:
                list.sort();
                cout << "Список отсортирован.\n";
                break;
            case 8:
                list.printToConsole();
                break;
            case 9: {
                string filename = getInput<string>("Введите имя файла для сохранения: ");
                list.printToFile(filename);
                cout << "Список сохранен в файл " << filename << ".\n";
                break;
            }
            case 10: {
                string filename = getInput<string>("Введите имя файла для загрузки: ");
                list.loadFromFile(filename);
                cout << "Список загружен из файла " << filename << ".\n";
                break;
            }
            case 11: {
                
                list.clear();
                cout << "Список пуст" << ".\n";
                break;
            }
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            }
        }
        catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}