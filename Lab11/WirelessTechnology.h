#pragma once
#include <string>
#include <vector>

class WirelessManager; // випереджувальне оголошення дружнього класу

class WirelessTechnology {
protected:
    std::string name;          // назва технології
    double frequencyGHz;       // робоча частота, ГГц
    double maxSpeedMbps;       // максимальна швидкість, Мбіт/с
    double maxRangeMeters;     // максимальна дальність, м

    // Вкладена структура + вектор (динамічний масив) з'єднань
    struct Connection {
        std::string deviceName;    // ім'я/назва пристрою
        double speedMbps;          // реальна швидкість, Мбіт/с
        double distanceMeters;     // відстань до пристрою, м
    };

    std::vector<Connection> connections;

public:
    WirelessTechnology(const std::string& name = "",
                       double frequencyGHz = 0.0,
                       double maxSpeedMbps = 0.0,
                       double maxRangeMeters = 0.0);

    virtual ~WirelessTechnology();

    virtual void printInfo() const;

    virtual void addConnection(const std::string& deviceName,
                               double speedMbps,
                               double distanceMeters);

    // середня швидкість по всіх з’єднаннях
    virtual double averageSpeed() const;

    // дружній клас, який має доступ до private/protected членів
    friend class WirelessManager;
};
