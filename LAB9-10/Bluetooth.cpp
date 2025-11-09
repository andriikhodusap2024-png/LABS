#include "Bluetooth.h"
#include <iostream>

Bluetooth::Bluetooth(std::string name, double frequency, double range, int version)
    : WirelessTechnology(name, frequency, range), version(version) {}

void Bluetooth::displayInfo() const {
    std::cout << "=== Bluetooth Information ===\n";
    std::cout << "Version: " << version << "\n";
    std::cout << "Frequency: " << frequency << " GHz\n";
    std::cout << "Range: " << range << " m\n";
}
