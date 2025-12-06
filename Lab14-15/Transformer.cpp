#include "Transformer.h"
#include <iostream>

Transformer::Transformer(double r, double v, double p)
    : ratio(r), primaryVoltage(v), power(p) {}

void Transformer::print() const {
    std::cout << "Трансформатор: коефіцієнт=" << ratio
              << ", первинна напруга=" << primaryVoltage
              << " В, потужність=" << power << " Вт";
}
