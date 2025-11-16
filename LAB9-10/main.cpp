#include <iostream>
#include <vector>
#include "WirelessTechnology.h"
#include "WiFi.h"
#include "Bluetooth.h"

int main() {
    std::vector<WirelessTechnology*> technologies;

    technologies.push_back(new WiFi("Home WiFi", 5.0, 80, "802.11ac"));
    technologies.push_back(new Bluetooth("Headset", 2.4, 15, 5));
    technologies.push_back(new WiFi("Office WiFi", 2.4, 120, "802.11n"));
    technologies.push_back(new Bluetooth("Speaker", 2.4, 30, 4));

    std::cout << "=== Wireless Technologies ===\n";
    for (auto* tech : technologies) {
        tech->displayInfo();
        std::cout << std::endl;
    }

    double totalRange = 0.0;
    for (auto* tech : technologies) {
        totalRange += tech->getRange();
    }

    double averageRange = totalRange / technologies.size();

    std::cout << "=== Summary Statistics ===\n";
    std::cout << "Average range of all wireless technologies: "
              << averageRange << " m\n";

    double maxFrequency = 0.0;
    for (auto* tech : technologies) {
        if (tech->getFrequency() > maxFrequency)
            maxFrequency = tech->getFrequency();
    }

    std::cout << "Maximum frequency among all technologies: "
              << maxFrequency << " GHz\n";

    for (auto* tech : technologies) {
        delete tech;
    }

    return 0;
}
