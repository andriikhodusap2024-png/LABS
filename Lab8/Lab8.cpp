#include <iostream>
#include <windows.h>
#include <vector>
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
    }

    Transformer(double k_, double U1_, double P_) {
        k = k_;
        U1 = U1_;
        P = P_;
    }

    void input() {
        cout << "коефіцієнт трансформації: ";
        cin >> k;
        cout << "первинну напругу (В): ";
        cin >> U1;
        cout << "потужність (Вт): ";
        cin >> P;
    }

    void output(int index) const {
        cout << "\nТрансформатор №" << index + 1 << ":\n";
        cout << "  Коефіцієнт трансформації: " << k << endl;
        cout << "  Первинна напруга (В): " << U1 << endl;
        cout << "  Потужність (Вт): " << P << endl;
        cout << "  Вторинна напруга (В): " << getSecondaryVoltage() << endl;
    }

    double getSecondaryVoltage() const {
        return U1 / k;
    }

    friend void modifyTransformer(Transformer &t) {
        cout << "\n=== Зміна параметрів трансформатора ===\n";
        cout << "новий коефіцієнт трансформації: ";
        cin >> t.k;
        cout << "нова первинна напруга (В): ";
        cin >> t.U1;
        cout << "нова потужність (Вт): ";
        cin >> t.P;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    system("chcp 65001 > nul");

    cout << "=== Програма: Трансформатор ===\n";

    Transformer t1; 
    t1.input();

    cout << "\n--- Поточні параметри ---";
    t1.output(0);

    Transformer &refT = t1;

    modifyTransformer(refT);

    cout << "\n--- Після зміни через посилання ---";
    t1.output(0);

    cout << "\nРоботу завершено успішно.\n";
    return 0;
}
