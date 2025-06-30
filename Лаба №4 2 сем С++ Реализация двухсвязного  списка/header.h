#ifndef LIST_H
#define LIST_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
using namespace std;
struct Car {
    string model;
    int year;
    double number;

    Car(const string& model, int year, double number)
        : model(model), year(year), number(number) {
    }

};

class DoublyLinkedList {
private:
    struct Node {
        Car data;
        Node* prev;
        Node* next;

        Node(const Car& data, Node* prev = nullptr, Node* next = nullptr)
            : data(data), prev(prev), next(next) {
        }
    };

    Node* head;
    Node* tail;
    size_t size;


   

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void clear();

    void addFront(const Car& car);
    void addBack(const Car& car);
    void addAt(const Car& car, size_t index);

    void removeFront();
    void removeBack();
    void removeAt(size_t index);

    void sort();
    void printToConsole() const;
    void printToFile(const string& filename) const;

    void loadFromFile(const string& filename);
};

#endif 

