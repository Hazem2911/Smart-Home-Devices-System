#include "../../Headers/Factory/BasicLedLight.h"
#include <iostream>
using namespace std;

BasicLedLight::BasicLedLight(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), status(DeviceStatus::OFF) {}

void BasicLedLight::turnOn() {
    status = DeviceStatus::ON;
    cout << "[BasicLedLight] " << name << " turned ON" << endl;
}

void BasicLedLight::turnOff() {
    status = DeviceStatus::OFF;
    cout << "[BasicLedLight] " << name << " turned OFF" << endl;
}

bool BasicLedLight::adjustbrightness(int level) {
    cout << "[BasicLedLight] " << name << " brightness set to " << level << endl;
    return true;
}

string  BasicLedLight::getType()   { return "BasicLedLight"; }
string  BasicLedLight::getId()     { return id; }
string  BasicLedLight::getName()   { return name; }
DeviceStatus BasicLedLight::getStatus() { return status; }
