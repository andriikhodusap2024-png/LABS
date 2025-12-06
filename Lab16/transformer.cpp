#include "transformer.h"

Transformer::Transformer()
    : k_(1.0), primaryVoltage_(220.0), power_(100.0)
{
    std::cout << u8"[КОНСТРУКТОР] Створено трансформатор (за замовчуванням)\n";
}

Transformer::Transformer(double k, double primaryVoltage, double power)
    : k_(k), primaryVoltage_(primaryVoltage), power_(power)
{
    std::cout << u8"[КОНСТРУКТОР] Створено трансформатор k = "
              << k_ << u8", U1 = " << primaryVoltage_
              << u8" В, P = " << power_ << u8" Вт\n";
}

Transformer::~Transformer()
{
    std::cout << u8"[ДЕСТРУКТОР] Знищено трансформатор k = "
              << k_ << u8", U1 = " << primaryVoltage_
              << u8" В, P = " << power_ << u8" Вт\n";
}

double Transformer::getTransformationRatio() const { return k_; }
double Transformer::getPrimaryVoltage() const { return primaryVoltage_; }
double Transformer::getPower() const { return power_; }

void Transformer::setTransformationRatio(double k) { k_ = k; }
void Transformer::setPrimaryVoltage(double v) { primaryVoltage_ = v; }
void Transformer::setPower(double p) { power_ = p; }

void Transformer::printInfo() const
{
    std::cout << u8"Трансформатор: k = " << k_
              << u8", U1 = " << primaryVoltage_
              << u8" В, P = " << power_ << u8" Вт\n";
}

