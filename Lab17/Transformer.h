#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <iostream>

class Transformer {
private:
    double ratio;          
    double primaryVoltage;  
    double power;           

public:
    Transformer(double r = 1.0, double v = 220.0, double p = 100.0);

    void setRatio(double r);
    void setPrimaryVoltage(double v);
    void setPower(double p);

    double getRatio() const;
    double getPrimaryVoltage() const;
    double getPower() const;

    void print() const;
};

#endif 
