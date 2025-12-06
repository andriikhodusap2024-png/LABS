#pragma once
#include <string>
#include <vector>

class WirelessTechnology {
public:
    struct Device {
        std::string model;
        double maxSpeedMbps{};
        double rangeMeters{};
        std::string notes;
    };

protected:
    std::string name;           
    std::string standard;       
    std::string frequencyBand;  
    std::vector<Device> devices;

public:
    WirelessTechnology(const std::string& name,
                       const std::string& standard,
                       const std::string& frequencyBand);

    virtual ~WirelessTechnology() = default;

    void addDevice(const Device& d);

    const std::vector<Device>& getDevices() const { return devices; }
    const std::string& getName() const { return name; }
    const std::string& getStandard() const { return standard; }
    const std::string& getFrequencyBand() const { return frequencyBand; }

    virtual void printInfo() const = 0;
    virtual std::string typeName() const = 0;

    WirelessTechnology& operator+=(const WirelessTechnology& other);

    bool operator<(const WirelessTechnology& other) const;
};
