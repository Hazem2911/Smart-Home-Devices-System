#include "../../Headers/Factory/BasicHalLight.h"
#include <iostream>
using namespace std;

BasicHalLight::BasicHalLight(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), status(DeviceStatus::OFF) {}

void BasicHalLight::turnOn() {
    status = DeviceStatus::ON;
    cout << "[BasicHalLight] " << name << " turned ON" << endl;
}

void BasicHalLight::turnOff() {
    status = DeviceStatus::OFF;
    cout << "[BasicHalLight] " << name << " turned OFF" << endl;
}

bool BasicHalLight::adjustbrightness(int level) {
    cout << "[BasicHalLight] " << name << " brightness set to " << level << endl;
    return true;
}

string  BasicHalLight::getType() { return "BasicHalLight"; }
string  BasicHalLight::getId() { return id; }
string  BasicHalLight::getName() { return name; }
DeviceStatus BasicHalLight::getStatus() { return status; }
