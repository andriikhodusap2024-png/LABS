#pragma once
#include "WirelessTechnology.h"

class Bluetooth : public WirelessTechnology {
    int version;  // наприклад, 4, 5

public:
    Bluetooth(int version = 5,
              double frequencyGHz = 2.4,
              double maxSpeedMbps = 3.0,
              double maxRangeMeters = 10.0);

    ~Bluetooth() override;

    void printInfo() const override;

    friend class WirelessManager;
};
