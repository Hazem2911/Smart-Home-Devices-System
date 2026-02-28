#include "../../Headers/Factory/PremiumHalogenLight.h"
#include <iostream>
using namespace std;

PremiumHalogenLight::PremiumHalogenLight(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), status(DeviceStatus::OFF) {}

void PremiumHalogenLight::turnOn() {
    status = DeviceStatus::ON;
    cout << "[PremiumHalogenLight] " << name << " turned ON" << endl;
}

void PremiumHalogenLight::turnOff() {
    status = DeviceStatus::OFF;
    cout << "[PremiumHalogenLight] " << name << " turned OFF" << endl;
}

bool PremiumHalogenLight::adjustbrightness(int level) {
    cout << "[PremiumHalogenLight] " << name << " brightness set to " << level << endl;
    return true;
}

string  PremiumHalogenLight::getType()   { return "PremiumHalogenLight"; }
string  PremiumHalogenLight::getId()     { return id; }
string  PremiumHalogenLight::getName()   { return name; }
DeviceStatus PremiumHalogenLight::getStatus() { return status; }
