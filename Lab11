#pragma execution_character_set("utf-8")
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Wireless {
protected:
    string name;
public:
    Wireless(string n) : name(n) {}
    virtual void show() const = 0;
    virtual ~Wireless() = default;

    friend class FriendDisplay;
};

class WiFi : public Wireless {
private:
    int speed;
public:
    WiFi(int s) : Wireless("WiFi"), speed(s) {}
    void show() const override {
        cout << "WiFi — швидкість: " << speed << " Мбіт/с\n";
    }
};

class Bluetooth : public Wireless {
private:
    double version;
public:
    Bluetooth(double v) : Wireless("Bluetooth"), version(v) {}
    void show() const override {
        cout << "Bluetooth — версія: " << version << "\n";
    }
};

class FriendDisplay {
public:
    static void showAll(const vector<Wireless*>& dev) {
        cout << "\n=== Виведення через дружній клас ===\n";
        for (auto d : dev) {
            cout << "Тип: " << d->name << "\n";
        }
    }
};

int main() {
    system("chcp 65001 > nul"); 

    vector<Wireless*> devices;

    devices.push_back(new WiFi(300));
    devices.push_back(new Bluetooth(5.0));

    cout << "=== Список пристроїв ===\n";
    for (auto d : devices) d->show();

    FriendDisplay::showAll(devices);

    for (auto d : devices) delete d;

    return 0;
}
