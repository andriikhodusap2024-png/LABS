#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Transformer.h"

struct Node {
    Transformer data;
    Node* prev;
    Node* next;

    Node(const Transformer& t) : data(t), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool isEmpty() const;

    void pushFront(const Transformer& t);
    void pushBack(const Transformer& t);
    bool insertAfter(double ratio, const Transformer& t);

    bool removeFront();
    bool removeBack();
    bool removeByRatio(double ratio);

    void displayForward() const;
    void displayBackward() const;
};


#endif
