#include <iostream>
#include <windows.h>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    DoublyLinkedList list;

    list.pushBack(Transformer(2.5, 220, 500));
    list.pushBack(Transformer(4.0, 380, 2000));
    list.pushFront(Transformer(1.8, 110, 300));

    list.displayForward();
    cout << endl;

    list.insertAfter(2.5, Transformer(3.3, 220, 750));
    list.displayForward();

    cout << "\nВидалення елемента з коефіцієнтом 4.0:\n";
    list.removeByRatio(4.0);
    list.displayForward();

    cout << "\nЗворотний вивід:\n";
    list.displayBackward();

    return 0;
}
