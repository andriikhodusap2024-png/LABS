#include "WirelessTechnology.h"
#include <iostream>

WirelessTechnology::WirelessTechnology(const std::string& name,
                                       const std::string& standard,
                                       const std::string& frequencyBand)
    : name(name),
      standard(standard),
      frequencyBand(frequencyBand) {}

void WirelessTechnology::addDevice(const Device& d) {
    devices.push_back(d);
}

WirelessTechnology& WirelessTechnology::operator+=(const WirelessTechnology& other) {
    devices.insert(devices.end(), other.devices.begin(), other.devices.end());
    return *this;
}

bool WirelessTechnology::operator<(const WirelessTechnology& other) const {
    return devices.size() < other.devices.size();
}
