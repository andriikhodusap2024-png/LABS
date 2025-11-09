#include "WiFi.h"
#include <iostream>

WiFi::WiFi(std::string name, double frequency, double range, std::string standard)
    : WirelessTechnology(name, frequency, range), standard(standard) {}

void WiFi::displayInfo() const {
    std::cout << "=== WiFi Information ===\n";
    std::cout << "Standard: " << standard << "\n";
    std::cout << "Frequency: " << frequency << " GHz\n";
    std::cout << "Range: " << range << " m\n";
}
