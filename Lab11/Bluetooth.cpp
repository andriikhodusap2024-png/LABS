#include "Bluetooth.h"
#include <iostream>

Bluetooth::Bluetooth(int version,
                     double frequencyGHz,
                     double maxSpeedMbps,
                     double maxRangeMeters)
    : WirelessTechnology("Bluetooth", frequencyGHz, maxSpeedMbps, maxRangeMeters),
      version(version) {}

Bluetooth::~Bluetooth() {
    // std::cout << "Destroy Bluetooth\n";
}

void Bluetooth::printInfo() const {
    std::cout << "=== Bluetooth ===\n";
    WirelessTechnology::printInfo();
    std::cout << "  Версія: " << version << "\n";
}
