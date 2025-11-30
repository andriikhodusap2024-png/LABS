#include "WirelessManager.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::string;

static void clearInput() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void WirelessManager::inputWiFi(WiFi& wifi) {
    cout << "Введення параметрів WiFi\n";
    cout << "Стандарт (наприклад 802.11ac): ";
    string standard;
    cin >> standard;

    cout << "Частота (ГГц): ";
    cin >> wifi.frequencyGHz;

    cout << "Максимальна швидкість (Мбіт/с): ";
    cin >> wifi.maxSpeedMbps;

    cout << "Максимальна дальність (м): ";
    cin >> wifi.maxRangeMeters;

    wifi.name = "WiFi";
    wifi.standard = standard;
}

void WirelessManager::inputBluetooth(Bluetooth& bt) {
    cout << "\nВведення параметрів Bluetooth\n";
    cout << "Версія (наприклад 5): ";
    cin >> bt.version;

    cout << "Частота (ГГц): ";
    cin >> bt.frequencyGHz;

    cout << "Максимальна швидкість (Мбіт/с): ";
    cin >> bt.maxSpeedMbps;

    cout << "Максимальна дальність (м): ";
    cin >> bt.maxRangeMeters;

    bt.name = "Bluetooth";
}

void WirelessManager::addConnections(WirelessTechnology& tech) {
    cout << "\nДодавання з'єднань для технології " << tech.name << "\n";
    cout << "Скільки з'єднань потрібно додати? ";
    int n;
    cin >> n;
    if (!cin || n <= 0) {
        clearInput();
        cout << "Невірне значення, з'єднання не будуть додані.\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        cout << "\nЗ'єднання #" << i + 1 << "\n";
        cout << "Назва пристрою: ";
        string dev;
        cin >> dev;

        cout << "Реальна швидкість (Мбіт/с): ";
        double s;
        cin >> s;

        cout << "Відстань до пристрою (м): ";
        double d;
        cin >> d;

        tech.addConnection(dev, s, d);
    }
}

void WirelessManager::printAll(const WiFi& wifi,
                               const Bluetooth& bt) const {
    cout << "\n===== Введені дані =====\n\n";

    wifi.printInfo();
    cout << "  Кількість з'єднань: " << wifi.connections.size() << "\n\n";

    bt.printInfo();
    cout << "  Кількість з'єднань: " << bt.connections.size() << "\n\n";
}

void WirelessManager::compareAverageSpeed(const WiFi& wifi,
                                          const Bluetooth& bt) const {
    double wifiAvg = wifi.averageSpeed();
    double btAvg = bt.averageSpeed();

    cout << "Середня швидкість WiFi: "      << wifiAvg << " Мбіт/с\n";
    cout << "Середня швидкість Bluetooth: " << btAvg   << " Мбіт/с\n";

    if (wifiAvg > btAvg) {
        cout << "=> За середньою швидкістю переважає WiFi.\n";
    } else if (btAvg > wifiAvg) {
        cout << "=> За середньою швидкістю переважає Bluetooth.\n";
    } else {
        cout << "=> Середні швидкості однакові.\n";
    }
}
