#include <iostream>
#include <locale>
#include <clocale>
#include <string>

#include "Device.h"
#include "Transformer.h"

#ifdef _WIN32
#include <windows.h>
#endif

void showMenu() {
    std::cout << "\n=== МЕНЮ ТРАНСФОРМАТОРА ===\n";
    std::cout << "1 - Ввести всі параметри заново\n";
    std::cout << "2 - Змінити лише коефіцієнт трансформації\n";
    std::cout << "3 - Змінити лише первинну напругу\n";
    std::cout << "4 - Змінити лише потужність\n";
    std::cout << "5 - Показати поточні параметри\n";
    std::cout << "0 - Вийти з програми\n";
    std::cout << "Ваш вибір: ";
}

void inputAllParameters(Transformer &t) {
    double k, u1, p;

    std::cout << "\nВведіть коефіцієнт трансформації: ";
    std::cin >> k;

    std::cout << "Введіть первинну напругу (В): ";
    std::cin >> u1;

    std::cout << "Введіть потужність (Вт): ";
    std::cin >> p;

    t.setRatio(k);
    t.setPrimaryVoltage(u1);
    t.setPower(p);
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    system("chcp 65001 > nul");
#endif

    std::setlocale(LC_ALL, "");

    std::cout << "=== Демонстрація шаблонів Device ===\n\n";

    Device<int> devInt(42);
    Device<double> devDouble(123.456);
    Device<std::string> devString("Тестовий рядок українською");

    devInt.print();
    devDouble.print();
    devString.print();

    std::cout << "\n=== Робота з класом Transformer (варіант 22) ===\n";

    Transformer t;
    inputAllParameters(t);

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            inputAllParameters(t);
            break;
        }
        case 2: {
            double k;
            std::cout << "Новий коефіцієнт трансформації: ";
            std::cin >> k;
            t.setRatio(k);
            break;
        }
        case 3: {
            double u1;
            std::cout << "Нова первинна напруга (В): ";
            std::cin >> u1;
            t.setPrimaryVoltage(u1);
            break;
        }
        case 4: {
            double p;
            std::cout << "Нова потужність (Вт): ";
            std::cin >> p;
            t.setPower(p);
            break;
        }
        case 5:
            t.print();
            break;
        case 0:
            std::cout << "Вихід з програми...\n";
            break;
        default:
            std::cout << "Невірний пункт меню. Спробуйте ще раз.\n";
        }

    } while (choice != 0);

    std::cout << "Програма завершила роботу.\n";
    return 0;
}
