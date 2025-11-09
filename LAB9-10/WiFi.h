#ifndef WIFI_H
#define WIFI_H

#include "WirelessTechnology.h"

class WiFi : public WirelessTechnology {
private:
    std::string standard;  

public:
    WiFi(std::string name = "WiFi", double frequency = 2.4, double range = 50.0, std::string standard = "802.11n");
    virtual void displayInfo() const override;
};

#endif
