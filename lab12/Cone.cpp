// Cone.cpp
#include "Cone.h"
#include <stdexcept>

// Конструктори
Cone::Cone() : radius(0.0), height(0.0) {}

Cone::Cone(double r, double h) : radius(0.0), height(0.0) {
    setRadius(r);
    setHeight(h);
}

// БЕЗ деструктора тут

// Геттери
double Cone::getRadius() const {
    return radius;
}

double Cone::getHeight() const {
    return height;
}

double Cone::getVolume() const {
    return (PI * radius * radius * height) / 3.0;
}

// Сеттери
void Cone::setRadius(double r) {
    if (r < 0) throw std::invalid_argument("Радіус не може бути від'ємним.");
    radius = r;
}

void Cone::setHeight(double h) {
    if (h < 0) throw std::invalid_argument("Висота не може бути від'ємною.");
    height = h;
}

// Оператор <=
bool operator<=(const Cone& left, const Cone& right) {
    return left.getVolume() <= right.getVolume();
}

// Оператор +
Cone operator+(const Cone& left, const Cone& right) {
    return Cone(left.radius + right.radius, left.height + right.height);
}

// Вивід
std::ostream& operator<<(std::ostream& os, const Cone& c) {
    os << "Конус(R=" << c.radius
       << ", H=" << c.height
       << ", V=" << c.getVolume() << ")";
    return os;
}
