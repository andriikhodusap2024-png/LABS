#pragma once
#include "WiFi.h"
#include "Bluetooth.h"

class WirelessManager {
public:
    WirelessManager() = default;
    ~WirelessManager() = default;

    void inputWiFi(WiFi& wifi);
    void inputBluetooth(Bluetooth& bt);

    // введення з'єднань для будь-якої бездротової технології
    void addConnections(WirelessTechnology& tech);

    // виведення всієї інформації
    void printAll(const WiFi& wifi, const Bluetooth& bt) const;

    // обробка: порівняння середньої швидкості
    void compareAverageSpeed(const WiFi& wifi, const Bluetooth& bt) const;
};
