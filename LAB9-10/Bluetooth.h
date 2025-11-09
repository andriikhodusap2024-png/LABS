#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "WirelessTechnology.h"

class Bluetooth : public WirelessTechnology {
private:
    int version;   

public:
    Bluetooth(std::string name = "Bluetooth", double frequency = 2.4, double range = 10.0, int version = 5);
    virtual void displayInfo() const override;
};

#endif
