//Общее задание :
//Для реализации проекта  методы описать в header(заголовочном) файле(*.h).Реализацию методов поместить в файл* .cpp, функцию main - в файл main.cpp.Использовать исключения.
//
//Для обработки стека(дека, очереди) реализовать функции :
//Создать класс
//Создание списка или дозапись элементов в список(чтение данных из файла)
//Добавить элемент(в начало, конец, по индексу)
//Удаление  элемента(в начале, в конце, по индексу)
//Удаление всех элементов
//Использовать исключения
//Сортировка списка
//Вывод списка на консоль и в файл
//Запросы на выполнение операций оформить в виде меню.
//Вместо char* -можно использовать string
//
//Примечание : код  функции добавления\удаления при сдаче преподавателю уметь написать по схеме, ответ будет засчитан как контрольная по спискам!
//
//Элемент списка  структура.Структура содержит информацию об автомобилях, поля: модель, год выпуска, номер(char*, int, double).

#include "header.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

void DoublyLinkedList::addFront(const Car& car) {
    Node* newNode = new Node(car, nullptr, head);
    if (head) head->prev = newNode;
    head = newNode;
    if (!tail) tail = head;
    ++size;
}

void DoublyLinkedList::addBack(const Car& car) {
    Node* newNode = new Node(car, tail, nullptr);
    if (tail) tail->next = newNode;
    tail = newNode;
    if (!head) head = tail;
    ++size;
}

void DoublyLinkedList::addAt(const Car& car, size_t index) {
    
    if (index == 0) {
        addFront(car);
        return;
    }
    if (index > size) throw out_of_range("Index out of range");
    if (index == size) { 
        addBack(car);
        return;
    } 
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    Node* newNode = new Node(car, current->prev, current);
    current->prev->next = newNode;
    current->prev = newNode;
    ++size;
}

void DoublyLinkedList::removeFront() {
    if (!head) throw underflow_error("List is empty");
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    --size;
}

void DoublyLinkedList::removeBack() {
    if (!tail) throw underflow_error("List is empty");
    Node* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    --size;
}

void DoublyLinkedList::removeAt(size_t index) {
    if (index == size-1) {
        removeBack();
        return;
    }
    if (index > size) throw out_of_range("Index out of range");
    if (index == 0) {
        removeFront();
        return;
    }
   
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    --size;
}

void DoublyLinkedList::sort() {
    if (!head) throw underflow_error("List is empty");
    if (!head || !head->next) return;
    vector<Car> cars;
    Node* current = head;
    while (current) {
        cars.push_back(current->data);
        current = current->next;
    }
    std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return a.model < b.model;
        });
    clear();
    for (const auto& car : cars) {
        addBack(car);
    }
}

void DoublyLinkedList::printToConsole() const {
    Node* current = head;
    while (current) {
        cout << "Model: " << current->data.model
            << ", Year: " << current->data.year
            << ", Number: " << current->data.number << endl;
        current = current->next;
    }
}

void DoublyLinkedList::printToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) throw ios_base::failure("Failed to open file");
    Node* current = head;
    while (current) {
        file << "Model: " << current->data.model
            << ", Year: " << current->data.year
            << ", Number: " << current->data.number << endl;
        current = current->next;
    }
}

void DoublyLinkedList::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) throw ios_base::failure("Failed to open file");
    //clear();
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string model;
        int year;
        double number;
        string tmp;
        if (getline(iss, tmp, ':') && getline(iss, model, ',')) {
            if (!model.empty() && model[0] == ' ') model = model.substr(1);
            if (getline(iss, tmp, ':') && (iss >> year)) {
                if (getline(iss, tmp, ':') && (iss >> number)) {
                    addBack(Car(model, year, number));
                }
            }
        }
    }
}

