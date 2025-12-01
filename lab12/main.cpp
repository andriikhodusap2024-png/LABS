#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <windows.h> 

#include "Cone.h"

int main() {

    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    try {
        int n;
        std::cout << "Введіть кількість конусів: ";
        std::cin >> n;

        if (!std::cin || n <= 0) {
            std::cout << "Помилка: некоректне значення.\n";
            return 0;
        }

        std::vector<Cone> cones;
        cones.reserve(n);

        std::cout << "Введіть радіус та висоту кожного конуса (R H):\n";

        for (int i = 0; i < n; ++i) {
            double r, h;
            std::cout << "Конус " << i + 1 << ": ";
            std::cin >> r >> h;

            if (!std::cin) {
                std::cout << "Помилка введення.\n";
                return 0;
            }

            cones.emplace_back(r, h);
        }

        std::cout << "\n--- Початкові дані ---\n";
        for (std::size_t i = 0; i < cones.size(); ++i) {
            std::cout << i + 1 << ": " << cones[i] << "\n";
        }

        
        std::sort(cones.begin(), cones.end(),
                  [](const Cone& a, const Cone& b) {
                      return a.getVolume() > b.getVolume();
                  });

        std::cout << "\n--- Відсортовано за спаданням об'єму ---\n";
        for (std::size_t i = 0; i < cones.size(); ++i) {
            std::cout << i + 1 << ": " << cones[i] << "\n";
        }

        
        double sumR = 0.0;
        double sumH = 0.0;

        for (const auto& c : cones) {
            sumR += c.getRadius();
            sumH += c.getHeight();
        }

        double avgR = sumR / cones.size();
        double avgH = sumH / cones.size();

        std::cout << std::fixed << std::setprecision(3);
        std::cout << "\nСередній радіус: " << avgR << "\n";
        std::cout << "Середня висота: " << avgH << "\n";

        
        if (cones.size() >= 2) {
            Cone sumCone = cones[0] + cones[1];

            std::cout << "\n--- Додавання двох перших конусів ---\n";
            std::cout << "Перший:  " << cones[0] << "\n";
            std::cout << "Другий:  " << cones[1] << "\n";
            std::cout << "Сума:    " << sumCone << "\n";
        }

        if (cones.size() >= 2) {
            std::cout << "\nПеревірка: об'єм першого конуса "
                      << (cones[0] <= cones[1] ? "<=" : ">")
                      << " об'єму другого.\n";
        }

    } catch (const std::exception& ex) {
        std::cerr << "Помилка: " << ex.what() << "\n";
    }

    return 0;
}
