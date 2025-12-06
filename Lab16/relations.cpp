#include "relations.h"

Primary::Primary(const std::string& n) : name(n)
{
    std::cout << u8"[КОНСТРУКТОР] Primary: " << name << "\n";
}

Primary::~Primary()
{
    std::cout << u8"[ДЕСТРУКТОР] Primary: " << name << "\n";
}

void Primary::print() const
{
    std::cout << u8"Primary: " << name << "\n";
}

Secondary::Secondary(const std::string& n) : name(n)
{
    std::cout << u8"[КОНСТРУКТОР] Secondary: " << name << "\n";
}

Secondary::~Secondary()
{
    std::cout << u8"[ДЕСТРУКТОР] Secondary: " << name << "\n";
}

void Secondary::print() const
{
    std::cout << u8"Secondary: " << name << "\n";
}
