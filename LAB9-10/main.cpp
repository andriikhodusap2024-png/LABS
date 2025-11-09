#include <iostream>
#include <vector>
#include "WirelessTechnology.h"
#include "WiFi.h"
#include "Bluetooth.h"

int main() {
    std::vector<WirelessTechnology*> technologies;

    technologies.push_back(new WiFi("Home WiFi", 5.0, 80, "802.11ac"));
    technologies.push_back(new Bluetooth("Headset", 2.4, 15, 5));

    std::cout << "=== Wireless Technologies ===\n";
    for (auto* tech : technologies) {
        tech->displayInfo();
        std::cout << std::endl;
    }

    for (auto* tech : technologies) {
        delete tech;
    }

    return 0;
}
