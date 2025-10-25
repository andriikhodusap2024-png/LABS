#pragma once
#include <iostream>
#include <array>
#include <string>
using namespace std;


struct TransformerData {
    double k;   
    double U1;  
    double P;   
};


class Transformer {
private:
    static const int SIZE = 3; 
    array<TransformerData, SIZE> data; 
    int count; 

public:
    Transformer();     
    ~Transformer();    

    void addTransformer(double k, double U1, double P);
    void showData() const;

    bool isValid(double k, double U1, double P) const;
};
