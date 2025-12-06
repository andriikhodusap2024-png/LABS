#include "Transformer.h"

Transformer::Transformer(double r, double v, double p)
    : ratio(r), primaryVoltage(v), power(p) {}

void Transformer::setRatio(double r) {
    ratio = r;
}

void Transformer::setPrimaryVoltage(double v) {
    primaryVoltage = v;
}

void Transformer::setPower(double p) {
    power = p;
}

double Transformer::getRatio() const {
    return ratio;
}

double Transformer::getPrimaryVoltage() const {
    return primaryVoltage;
}

double Transformer::getPower() const {
    return power;
}

void Transformer::print() const {
    std::cout << "=== Трансформатор ===\n";
    std::cout << "Коефіцієнт трансформації: " << ratio << "\n";
    std::cout << "Первинна напруга: " << primaryVoltage << " В\n";
    std::cout << "Потужність: " << power << " Вт\n";
}
