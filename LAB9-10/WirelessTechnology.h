#ifndef WIRELESSTECHNOLOGY_H
#define WIRELESSTECHNOLOGY_H

#include <string>
#include <iostream>

class WirelessTechnology {
protected:
    std::string name;      
    double frequency;       
    double range;           

public:
    WirelessTechnology(std::string name = "Unknown", double frequency = 0.0, double range = 0.0);
    virtual ~WirelessTechnology();


    virtual void displayInfo() const;

    void setName(const std::string& newName);
    void setFrequency(double newFrequency);
    void setRange(double newRange);

    std::string getName() const;
    double getFrequency() const;
    double getRange() const;
};

#endif
