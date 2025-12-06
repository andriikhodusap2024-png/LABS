#pragma once
#include "WirelessTechnology.h"

class Bluetooth : public WirelessTechnology {
    int version; 

public:
    Bluetooth(const std::string& standard,
              const std::string& frequencyBand,
              int version);

    int getVersion() const { return version; }

    void printInfo() const override;
    std::string typeName() const override { return "Bluetooth"; }
};
