#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

bool DoublyLinkedList::isEmpty() const {
    return head == nullptr;
}

void DoublyLinkedList::pushFront(const Transformer& t) {
    Node* node = new Node(t);
    if (isEmpty()) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    std::cout << "Елемент додано на початок.\n";
}

void DoublyLinkedList::pushBack(const Transformer& t) {
    Node* node = new Node(t);
    if (isEmpty()) {
        head = tail = node;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    std::cout << "Елемент додано в кінець.\n";
}

bool DoublyLinkedList::insertAfter(double ratio, const Transformer& t) {
    Node* cur = head;
    while (cur) {
        if (cur->data.getRatio() == ratio) {
            Node* node = new Node(t);
            node->next = cur->next;
            node->prev = cur;

            if (cur->next)
                cur->next->prev = node;
            else
                tail = node;

            cur->next = node;
            std::cout << "Елемент вставлено після коефіцієнта " << ratio << ".\n";
            return true;
        }
        cur = cur->next;
    }
    std::cout << "Елемент із таким коефіцієнтом не знайдено.\n";
    return false;
}

bool DoublyLinkedList::removeFront() {
    if (isEmpty()) return false;

    Node* temp = head;
    if (head == tail)
        head = tail = nullptr;
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    std::cout << "Елемент видалено з початку.\n";
    return true;
}

bool DoublyLinkedList::removeBack() {
    if (isEmpty()) return false;

    Node* temp = tail;
    if (head == tail)
        head = tail = nullptr;
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    std::cout << "Елемент видалено з кінця.\n";
    return true;
}

bool DoublyLinkedList::removeByRatio(double ratio) {
    Node* cur = head;
    while (cur) {
        if (cur->data.getRatio() == ratio) {

            if (cur == head) return removeFront();
            if (cur == tail) return removeBack();

            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;

            delete cur;
            std::cout << "Елемент з коефіцієнтом " << ratio << " видалено.\n";
            return true;
        }
        cur = cur->next;
    }
    std::cout << "Елемент не знайдено.\n";
    return false;
}

void DoublyLinkedList::displayForward() const {
    if (isEmpty()) {
        std::cout << "Список порожній.\n";
        return;
    }
    std::cout << "Прямий список:\n";
    Node* cur = head;
    while (cur) {
        cur->data.print();
        std::cout << "\n";
        cur = cur->next;
    }
}

void DoublyLinkedList::displayBackward() const {
    if (isEmpty()) {
        std::cout << "Список порожній.\n";
        return;
    }
    std::cout << "Зворотний список:\n";
    Node* cur = tail;
    while (cur) {
        cur->data.print();
        std::cout << "\n";
        cur = cur->prev;
    } 
    
}
