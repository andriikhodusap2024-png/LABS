#pragma once
#include "WirelessTechnology.h"

class WiFi : public WirelessTechnology {
    int maxClients; 

public:
    WiFi(const std::string& standard,
         const std::string& frequencyBand,
         int maxClients);

    int getMaxClients() const { return maxClients; }

    void printInfo() const override;
    std::string typeName() const override { return "WiFi"; }
};
