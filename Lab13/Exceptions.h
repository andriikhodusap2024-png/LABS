#pragma once
#include <stdexcept>
#include <string>

class InputException : public std::runtime_error {
public:
    explicit InputException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class FileException : public std::runtime_error {
public:
    explicit FileException(const std::string& msg)
        : std::runtime_error(msg) {}
};
