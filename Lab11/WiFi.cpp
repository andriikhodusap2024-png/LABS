#include "WiFi.h"
#include <iostream>

WiFi::WiFi(const std::string& standard,
           double frequencyGHz,
           double maxSpeedMbps,
           double maxRangeMeters)
    : WirelessTechnology("WiFi", frequencyGHz, maxSpeedMbps, maxRangeMeters),
      standard(standard) {}

WiFi::~WiFi() {
    // std::cout << "Destroy WiFi\n";
}

void WiFi::printInfo() const {
    std::cout << "=== WiFi ===\n";
    WirelessTechnology::printInfo();
    std::cout << "  Стандарт: " << standard << "\n";
}
