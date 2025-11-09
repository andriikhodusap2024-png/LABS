#include "WirelessTechnology.h"

WirelessTechnology::WirelessTechnology(std::string name, double frequency, double range)
    : name(name), frequency(frequency), range(range) {}

WirelessTechnology::~WirelessTechnology() {
    std::cout << "Destroying WirelessTechnology: " << name << std::endl;
}

void WirelessTechnology::displayInfo() const {
    std::cout << "Technology: " << name
              << "\nFrequency: " << frequency << " GHz"
              << "\nRange: " << range << " m\n";
}

void WirelessTechnology::setName(const std::string& newName) {
    if (!newName.empty()) name = newName;
}

void WirelessTechnology::setFrequency(double newFrequency) {
    if (newFrequency > 0 && newFrequency < 1000) frequency = newFrequency;
}

void WirelessTechnology::setRange(double newRange) {
    if (newRange > 0 && newRange < 100000) range = newRange;
}

std::string WirelessTechnology::getName() const { return name; }
double WirelessTechnology::getFrequency() const { return frequency; }
double WirelessTechnology::getRange() const { return range; }
