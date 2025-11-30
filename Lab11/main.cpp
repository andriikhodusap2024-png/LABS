#include <iostream>
#include <clocale>          // важливо для setlocale
#include "WirelessManager.h"

int main() {
    // Увімкнути локаль (спроба переключити на українську / UTF-8)
    // Якщо "uk_UA.UTF-8" не підтримується системою, можна залишити просто ""
    std::setlocale(LC_ALL, "uk_UA.UTF-8");
    // std::setlocale(LC_ALL, "");  // запасний варіант: взяти локаль системи

    std::cout << "Лабораторна робота №11. Бездротові технології (WiFi, Bluetooth)\n\n";

    WiFi wifi;
    Bluetooth bt;
    WirelessManager manager;

    // Введення параметрів технологій
    manager.inputWiFi(wifi);
    manager.inputBluetooth(bt);

    // Додавання з'єднань
    manager.addConnections(wifi);
    manager.addConnections(bt);

    // Вивід усіх даних
    manager.printAll(wifi, bt);

    // Обробка: порівняння середніх швидкостей
    std::cout << "----- Результат обробки даних -----\n";
    manager.compareAverageSpeed(wifi, bt);

    std::cout << "\nПрограма завершила роботу.\n";
    return 0;
}
