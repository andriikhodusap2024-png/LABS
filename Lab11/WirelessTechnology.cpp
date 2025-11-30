#include "WirelessTechnology.h"
#include <iostream>
#include <iomanip>

WirelessTechnology::WirelessTechnology(const std::string& name,
                                       double frequencyGHz,
                                       double maxSpeedMbps,
                                       double maxRangeMeters)
    : name(name),
      frequencyGHz(frequencyGHz),
      maxSpeedMbps(maxSpeedMbps),
      maxRangeMeters(maxRangeMeters) {}

WirelessTechnology::~WirelessTechnology() {
    
    
}

void WirelessTechnology::printInfo() const {
    std::cout << "Технологія: " << name << "\n"
              << "  Частота: "      << frequencyGHz   << " ГГц\n"
              << "  Макс. швидкість: " << maxSpeedMbps   << " Мбіт/с\n"
              << "  Макс. дальність: " << maxRangeMeters << " м\n";
}

void WirelessTechnology::addConnection(const std::string& deviceName,
                                       double speedMbps,
                                       double distanceMeters) {
    Connection c{deviceName, speedMbps, distanceMeters};
    connections.push_back(c);
}

double WirelessTechnology::averageSpeed() const {
    if (connections.empty()) return 0.0;

    double sum = 0.0;
    for (const auto& c : connections) {
        sum += c.speedMbps;
    }
    return sum / connections.size();
}
