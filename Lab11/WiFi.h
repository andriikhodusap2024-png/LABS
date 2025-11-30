#pragma once
#include "WirelessTechnology.h"
#include <string>

class WiFi : public WirelessTechnology {
    std::string standard;  // наприклад, 802.11n, 802.11ac тощо

public:
    WiFi(const std::string& standard = "802.11ac",
         double frequencyGHz = 5.0,
         double maxSpeedMbps = 1300.0,
         double maxRangeMeters = 70.0);

    ~WiFi() override;

    void printInfo() const override;

    friend class WirelessManager;
};
