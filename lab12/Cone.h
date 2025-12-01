// Cone.h
#pragma once

#include <iostream>

class Cone {
private:
    double radius;
    double height;
    static constexpr double PI = 3.14159265358979323846;

public:
    Cone();
    Cone(double r, double h);
    // ~Cone();  <-- ВИДАЛИТИ ЦЕ

    double getRadius() const;
    double getHeight() const;
    double getVolume() const;

    void setRadius(double r);
    void setHeight(double h);

    friend bool operator<=(const Cone& left, const Cone& right);
    friend Cone operator+(const Cone& left, const Cone& right);
    friend std::ostream& operator<<(std::ostream& os, const Cone& c);
};
