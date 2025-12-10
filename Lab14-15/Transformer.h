#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>

class Transformer {
private:
    double ratio;          
    double primaryVoltage; 
    double power;          

public:
    Transformer(double r = 1.0, double v = 220.0, double p = 100.0);

    void print() const;

    double getRatio() const { return ratio; }
    double getPrimaryVoltage() const { return primaryVoltage; }
    double getPower() const { return power; }
};


#endif
