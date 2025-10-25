#include "Transformer.h"
#include <windows.h>

Transformer::Transformer() {
    count = 0;
    cout << "Створено об'єкт класу Transformer" << endl;
}


Transformer::~Transformer() {
    cout << "Звільнено пам'ять об'єкта Transformer" << endl;
}


bool Transformer::isValid(double k, double U1, double P) const {
    if (k <= 0 || U1 <= 0 || P <= 0) {
        cout << " Помилка: усі значення мають бути додатні!" << endl;
        return false;
    }
    return true;
}


void Transformer::addTransformer(double k, double U1, double P) {
    if (count < SIZE && isValid(k, U1, P)) {
        data[count] = {k, U1, P};
        count++;
        cout << " Дані успішно додано!" << endl;
    } else if (count >= SIZE) {
        cout << " Масив заповнено, додавання неможливе!" << endl;
    }
}


void Transformer::showData() const {
    cout << "\n=== Дані про трансформатори ===" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ") k=" << data[i].k
             << ", U1=" << data[i].U1
             << " В, P=" << data[i].P << " Вт" << endl;
    }
    if (count == 0)
        cout << "Масив порожній!" << endl;
}
