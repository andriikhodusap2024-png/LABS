#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>

template <typename T>
class Device {
protected:
    T value;

public:
    Device(T v) : value(v) {}

    void print() const {
        std::cout << "Загальне значення: " << value << std::endl;
    }
};

template <>
class Device<double> {
private:
    double value;

public:
    Device(double v) : value(v) {}

    void print() const {
        std::cout << "Спеціалізація для double → "
                  << std::scientific << value << std::endl;
    }
};

template <typename CharT>
class Device<std::basic_string<CharT>> {
private:
    std::basic_string<CharT> value;

public:
    Device(std::basic_string<CharT> v) : value(v) {}

    void print() const {
        std::cout << "Рядкове значення → \"" << value << "\"" << std::endl;
    }
};

#endif 
