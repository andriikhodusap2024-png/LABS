#pragma once

#include <iostream>

class Transformer {
private:
    double k_;               
    double primaryVoltage_;  
    double power_;           

public:
    Transformer();
    Transformer(double k, double primaryVoltage, double power);
    ~Transformer();

    double getTransformationRatio() const;
    double getPrimaryVoltage() const;
    double getPower() const;

    void setTransformationRatio(double k);
    void setPrimaryVoltage(double v);
    void setPower(double p);

    void printInfo() const;
};

