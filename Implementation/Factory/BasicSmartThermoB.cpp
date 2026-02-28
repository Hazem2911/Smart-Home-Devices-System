#include "../../Headers/Factory/BasicSmartThermoB.h"
#include <iostream>
using namespace std;

BasicSmartThermoB::BasicSmartThermoB(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), currentTemperature(20.0), targetTemperature(22.0),
      mode(ThermoMode::AUTO), status(DeviceStatus::OFF) {}

void BasicSmartThermoB::setTargetTemperature(double temp) {
    targetTemperature = temp;
    cout << "[BasicSmartThermoB] Target temperature set to " << temp << endl;
}

double BasicSmartThermoB::getTargetTemperature()  { return targetTemperature; }
double BasicSmartThermoB::getCurrentTemperature() { return currentTemperature; }

void BasicSmartThermoB::setMode(ThermoMode m) {
    mode = m;
    cout << "[BasicSmartThermoB] Mode set to " << (int)m << endl;
}

ThermoMode BasicSmartThermoB::getMode() { return mode; }

void BasicSmartThermoB::turnOn() {
    status = DeviceStatus::ON;
    cout << "[BasicSmartThermoB] " << name << " turned ON" << endl;
}

void BasicSmartThermoB::turnOff() {
    status = DeviceStatus::OFF;
    cout << "[BasicSmartThermoB] " << name << " turned OFF" << endl;
}

string  BasicSmartThermoB::getId()     { return id; }
string  BasicSmartThermoB::getName()   { return name; }
DeviceStatus BasicSmartThermoB::getStatus() { return status; }
