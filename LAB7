#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <limits>
using namespace std;

struct Transformer {
    double k;     
    double U1;    
    double P;     
};

class TransformerSystem {
private:
    vector<Transformer> list;

public:
    void addTransformer(double k, double U1, double P) {
        Transformer t = { k, U1, P };
        list.push_back(t);
    }

    void showAll() const {
        if (list.empty()) {
            wcout << L"\nСписок порожній.\n";
            return;
        }

        wcout << L"\nСписок трансформаторів:\n";
        for (size_t i = 0; i < list.size(); ++i) {
            wcout << i + 1 << L". k = " << list[i].k
                  << L", U1 = " << list[i].U1
                  << L" В, P = " << list[i].P << L" Вт\n";
        }
    }

    void findByK(double searchK) const {
        bool found = false;
        wcout << L"\nПошук трансформатора з коефіцієнтом " << searchK << L":\n";
        for (const auto& t : list) {
            if (t.k == searchK) {
                wcout << L"U1 = " << t.U1 << L" В, P = " << t.P << L" Вт\n";
                found = true;
            }
        }
        if (!found) wcout << L"Нічого не знайдено.\n";
    }

    void clearAll() {
        list.clear();
        wcout << L"Список очищено.\n";
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    TransformerSystem ts;
    int choice;

    do {
        wcout << L"\n=== МЕНЮ ===\n";
        wcout << L"1. Додати трансформатор\n";
        wcout << L"2. Показати всі трансформатори\n";
        wcout << L"3. Знайти трансформатор за коефіцієнтом трансформації\n";
        wcout << L"4. Очистити список\n";
        wcout << L"0. Вийти\n";
        wcout << L"Ваш вибір: ";
        wcin >> choice;

        if (wcin.fail()) {
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
            wcout << L"Помилка вводу. Спробуйте ще раз.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            double k, U1, P;
            wcout << L"Введіть коефіцієнт трансформації: ";
            wcin >> k;
            wcout << L"Введіть первинну напругу (В): ";
            wcin >> U1;
            wcout << L"Введіть потужність (Вт): ";
            wcin >> P;
            ts.addTransformer(k, U1, P);
            break;
        }

        case 2:
            ts.showAll();
            break;

        case 3: {
            double searchK;
            wcout << L"Введіть коефіцієнт для пошуку: ";
            wcin >> searchK;
            ts.findByK(searchK);
            break;
        }

        case 4:
            ts.clearAll();
            break;

        case 0:
            wcout << L"Програму завершено.\n";
            break;

        default:
            wcout << L"Невірний вибір.\n";
        }

    } while (choice != 0);

    return 0;
}
