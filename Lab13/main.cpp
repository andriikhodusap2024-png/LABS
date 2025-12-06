#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <fstream>

#include "WiFi.h"
#include "Bluetooth.h"
#include "Exceptions.h"

#ifdef _WIN32
    #include <windows.h>
#endif

int readInt(const std::string& prompt) {
    int value;
    std::cout << prompt;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InputException("Некоректне ціле число.");
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

double readDouble(const std::string& prompt) {
    double value;
    std::cout << prompt;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InputException("Некоректне дробове число.");
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

std::string readLine(const std::string& prompt) {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}

void createWiFi(std::vector<std::unique_ptr<WirelessTechnology>>& list) {
    std::string standard = readLine("Введіть стандарт WiFi (наприклад, 802.11ac): ");
    std::string band     = readLine("Введіть частотний діапазон (наприклад, 2.4/5 ГГц): ");
    int maxClients       = readInt("Введіть максимальну кількість клієнтів: ");

    auto wifi = std::make_unique<WiFi>(standard, band, maxClients);

    int devCount = readInt("Скільки пристроїв додати для цієї технології? ");
    for (int i = 0; i < devCount; ++i) {
        std::cout << "Введення пристрою #" << i + 1 << ":\n";
        WirelessTechnology::Device d;
        d.model         = readLine("  Модель: ");
        d.maxSpeedMbps  = readDouble("  Макс. швидкість (Мбіт/с): ");
        d.rangeMeters   = readDouble("  Дальність (м): ");
        d.notes         = readLine("  Примітки: ");
        wifi->addDevice(d);
    }

    list.push_back(std::move(wifi));
    std::cout << "Об'єкт WiFi успішно створено.\n";
}

void createBluetooth(std::vector<std::unique_ptr<WirelessTechnology>>& list) {
    std::string standard = readLine("Введіть стандарт Bluetooth (наприклад, Bluetooth 5.0): ");
    std::string band     = readLine("Введіть частотний діапазон (наприклад, 2.4 ГГц): ");
    int version          = readInt("Введіть номер версії (наприклад, 4 або 5): ");

    auto bt = std::make_unique<Bluetooth>(standard, band, version);

    int devCount = readInt("Скільки пристроїв додати для цієї технології? ");
    for (int i = 0; i < devCount; ++i) {
        std::cout << "Введення пристрою #" << i + 1 << ":\n";
        WirelessTechnology::Device d;
        d.model         = readLine("  Модель: ");
        d.maxSpeedMbps  = readDouble("  Макс. швидкість (Мбіт/с): ");
        d.rangeMeters   = readDouble("  Дальність (м): ");
        d.notes         = readLine("  Примітки: ");
        bt->addDevice(d);
    }

    list.push_back(std::move(bt));
    std::cout << "Об'єкт Bluetooth успішно створено.\n";
}

void printAll(const std::vector<std::unique_ptr<WirelessTechnology>>& list) {
    if (list.empty()) {
        std::cout << "Список порожній.\n";
        return;
    }

    std::cout << "=== УСІ ЗАРЕЄСТРОВАНІ БЕЗДРОТОВІ ТЕХНОЛОГІЇ ===\n";

    for (std::size_t i = 0; i < list.size(); ++i) {
        std::cout << "Об'єкт #" << i + 1 << ":\n";
        list[i]->printInfo();
    }

    if (list.size() >= 2) {
        const auto& a = list[0];
        const auto& b = list[1];

        std::cout << "Порівняння перших двох технологій за кількістю пристроїв:\n";
        if (*a < *b) {
            std::cout << "  У першої технології менше пристроїв.\n";
        } else if (*b < *a) {
            std::cout << "  У першої технології більше пристроїв.\n";
        } else {
            std::cout << "  Кількість пристроїв однакова.\n";
        }
    }
}

void saveToFile(const std::vector<std::unique_ptr<WirelessTechnology>>& list,
                const std::string& fileName) {

    std::fstream file(fileName, std::ios::out | std::ios::trunc);
    if (!file) {
        throw FileException("Не вдалося відкрити файл для запису.");
    }

    for (const auto& t : list) {
        if (const auto* wifi = dynamic_cast<const WiFi*>(t.get())) {
            file << "WiFi\n";
            file << wifi->getStandard() << "\n";
            file << wifi->getFrequencyBand() << "\n";
            file << wifi->getMaxClients() << "\n";
        } else if (const auto* bt = dynamic_cast<const Bluetooth*>(t.get())) {
            file << "Bluetooth\n";
            file << bt->getStandard() << "\n";
            file << bt->getFrequencyBand() << "\n";
            file << bt->getVersion() << "\n";
        } else continue;

        const auto& devs = t->getDevices();
        file << devs.size() << "\n";

        for (const auto& d : devs) {
            file << d.model << "\n";
            file << d.maxSpeedMbps << "\n";
            file << d.rangeMeters << "\n";
            file << d.notes << "\n";
        }
    }

    std::cout << "Дані збережено у файл \"" << fileName << "\".\n";
}

void loadFromFile(std::vector<std::unique_ptr<WirelessTechnology>>& list,
                  const std::string& fileName) {

    std::fstream file(fileName, std::ios::in);
    if (!file) throw FileException("Не вдалося відкрити файл для читання.");

    list.clear();

    std::string type;
    while (std::getline(file, type)) {
        if (type.empty()) continue;

        std::string standard, band;
        std::getline(file, standard);
        std::getline(file, band);

        int extra;
        file >> extra;
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        size_t devCount;
        file >> devCount;
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::unique_ptr<WirelessTechnology> tech;

        if (type == "WiFi")
            tech = std::make_unique<WiFi>(standard, band, extra);
        else if (type == "Bluetooth")
            tech = std::make_unique<Bluetooth>(standard, band, extra);
        else
            throw FileException("Невідомий тип у файлі: " + type);

        for (size_t i = 0; i < devCount; ++i) {
            WirelessTechnology::Device d;
            std::getline(file, d.model);
            file >> d.maxSpeedMbps;
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            file >> d.rangeMeters;
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(file, d.notes);
            tech->addDevice(d);
        }

        list.push_back(std::move(tech));
    }

    std::cout << "Дані успішно завантажено.\n";
}

void printMenu() {
    std::cout << "\n===== МЕНЮ =====\n";
    std::cout << "1. Додати технологію WiFi\n";
    std::cout << "2. Додати технологію Bluetooth\n";
    std::cout << "3. Показати всі технології\n";
    std::cout << "4. Зберегти в файл\n";
    std::cout << "5. Завантажити з файлу\n";
    std::cout << "0. Вихід\n";
    std::cout << "Ваш вибір: ";
}

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    std::vector<std::unique_ptr<WirelessTechnology>> technologies;
    const std::string fileName = "wireless_tech.txt";

    bool running = true;

    while (running) {
        try {
            printMenu();
            int choice;

            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InputException("Потрібно ввести номер пункту меню.");
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (choice) {
                case 1: createWiFi(technologies); break;
                case 2: createBluetooth(technologies); break;
                case 3: printAll(technologies); break;
                case 4: saveToFile(technologies, fileName); break;
                case 5: loadFromFile(technologies, fileName); break;
                case 0: running = false; break;
                default: std::cout << "Невідомий пункт меню.\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка: " << e.what() << "\n";
        }
        catch (...) {
            std::cerr << "Невідома виняткова ситуація!\n";
        }
    }

    std::cout << "Програма завершила роботу.\n";
    return 0;
}
