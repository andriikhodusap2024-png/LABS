#pragma once

#include <iostream>
#include <memory>
#include <string>

class Secondary;

class Primary {
public:
    std::string name;
    std::shared_ptr<Secondary> secondary;

    explicit Primary(const std::string& n);
    ~Primary();

    void print() const;
};

class Secondary {
public:
    std::string name;
    std::weak_ptr<Primary> primary;

    explicit Secondary(const std::string& n);
    ~Secondary();

    void print() const;
};
