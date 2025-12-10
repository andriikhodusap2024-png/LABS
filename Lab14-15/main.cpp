#include <iostream>
#include <windows.h>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    DoublyLinkedList list;

    cout << "Створення та заповнення списку...\n";
    list.pushBack(Transformer(2.5, 220, 500));
    list.pushBack(Transformer(4.0, 380, 2000));
    list.pushFront(Transformer(1.8, 110, 300));

    cout << "\nПочатковий список (прямий вивід):\n";
    list.displayForward();

    cout << "\nВставка елемента після коефіцієнта 2.5:\n";
    list.insertAfter(2.5, Transformer(3.3, 220, 750));
    list.displayForward();

    cout << "\nВидалення елемента з коефіцієнтом 4.0:\n";
    list.removeByRatio(4.0);
    list.displayForward();

    cout << "\nВидалення елемента з початку:\n";
    list.removeFront();
    list.displayForward();

    cout << "\nВидалення елемента з кінця:\n";
    list.removeBack();
    list.displayForward();

    cout << "\nЗворотний вивід списку:\n";
    list.displayBackward();

    return 0;
    
}
