#include <iostream>
#include <windows.h>
using namespace std;

class Transformer {
private:
    double k;   
    double U1;  
    double P;   

public:
    Transformer() {
        k = 1.0;
        U1 = 220.0;
        P = 1000.0;
        cout << "Викликано конструктор за замовчуванням\n";
    }

    Transformer(double coef, double voltage, double power) {
        if (coef > 0 && voltage > 0 && power > 0) {
            k = coef;
            U1 = voltage;
            P = power;
        } else {
            cout << "Помилка! Невірні вхідні дані. Використано значення за замовчуванням.\n";
            k = 1.0;
            U1 = 220.0;
            P = 1000.0;
        }
        cout << "Викликано конструктор з параметрами\n";
    }

    ~Transformer() {
        cout << "Деструктор викликано для трансформатора (k = " << k << ")\n";
    }

    void setK(double coef) {
        if (coef > 0)
            k = coef;
        else
            cout << "Коефіцієнт трансформації повинен бути > 0!\n";
    }

    void setU1(double voltage) {
        if (voltage > 0)
            U1 = voltage;
        else
            cout << "Первинна напруга повинна бути > 0!\n";
    }

    void setP(double power) {
        if (power > 0)
            P = power;
        else
            cout << "Потужність повинна бути > 0!\n";
    }

    double getK() const { return k; }
    double getU1() const { return U1; }
    double getP() const { return P; }

    void input() {
        cout << "Введіть коефіцієнт трансформації: ";
        cin >> k;
        cout << "Введіть первинну напругу (В): ";
        cin >> U1;
        cout << "Введіть потужність (Вт): ";
        cin >> P;

        if (k <= 0 || U1 <= 0 || P <= 0) {
            cout << "Помилка! Усі параметри повинні бути позитивними. Встановлено значення за замовчуванням.\n";
            k = 1.0;
            U1 = 220.0;
            P = 1000.0;
        }
    }

    void display() const {
        cout << "=== Дані трансформатора ===\n";
        cout << "Коефіцієнт трансформації: " << k << endl;
        cout << "Первинна напруга (В): " << U1 << endl;
        cout << "Потужність (Вт): " << P << endl;
        cout << "Вторинна напруга (В): " << U1 / k << endl;
    }

    bool matchesPower(double minPower) const {
        return P >= minPower;
    }
};

int main() {
    SetConsoleOutputCP(65001);  
    SetConsoleCP(65001);
    cout << "=== Демонстрація класу Transformer ===\n";

    Transformer t1; 
    t1.display();

    cout << "\n---\n";

    Transformer t2(10.0, 2200.0, 5000.0); 
    t2.display();

    cout << "\n--- Введення нового трансформатора з клавіатури ---\n";
    Transformer t3;
    t3.input();
    t3.display();

    cout << "\n--- Перевірка трансформаторів за критерієм потужності ---\n";
    double minPower;
    cout << "Введіть мінімальну потужність (Вт): ";
    cin >> minPower;

    bool found = false;
    if (t1.matchesPower(minPower)) {
        cout << "\nТрансформатор 1 задовольняє умову:\n";
        t1.display();
        found = true;
    }
    if (t2.matchesPower(minPower)) {
        cout << "\nТрансформатор 2 задовольняє умову:\n";
        t2.display();
        found = true;
    }
    if (t3.matchesPower(minPower)) {
        cout << "\nТрансформатор 3 задовольняє умову:\n";
        t3.display();
        found = true;
    }

    if (!found)
        cout << "\n❗ Жоден трансформатор не задовольняє заданому критерію.\n";

    return 0;
}
