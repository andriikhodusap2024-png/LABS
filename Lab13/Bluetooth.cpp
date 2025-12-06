#include "Bluetooth.h"
#include <iostream>

Bluetooth::Bluetooth(const std::string& standard,
                     const std::string& frequencyBand,
                     int version)
    : WirelessTechnology("Bluetooth", standard, frequencyBand),
      version(version) {}

void Bluetooth::printInfo() const {
    std::cout << "=== Технологія Bluetooth ===\n";
    std::cout << "Стандарт: " << standard << "\n";
    std::cout << "Частотний діапазон: " << frequencyBand << "\n";
    std::cout << "Версія: " << version << "\n";
    std::cout << "Кількість пристроїв: " << devices.size() << "\n";

    for (std::size_t i = 0; i < devices.size(); ++i) {
        const auto& d = devices[i];
        std::cout << "  Пристрій #" << i + 1 << ":\n";
        std::cout << "    Модель: " << d.model << "\n";
        std::cout << "    Макс. швидкість, Мбіт/с: " << d.maxSpeedMbps << "\n";
        std::cout << "    Дальність, м: " << d.rangeMeters << "\n";
        std::cout << "    Примітки: " << d.notes << "\n";
    }
    std::cout << "----------------------------\n";
}
