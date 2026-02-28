#include "../../Headers/Factory/BasicSmartThermoA.h"
#include <iostream>
using namespace std;

BasicSmartThermoA::BasicSmartThermoA(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), currentTemperature(20.0), targetTemperature(22.0),
      mode(ThermoMode::AUTO), status(DeviceStatus::OFF) {}

void BasicSmartThermoA::setTargetTemperature(double temp) {
    targetTemperature = temp;
    cout << "[BasicSmartThermoA] Target temperature set to " << temp << endl;
}

double BasicSmartThermoA::getTargetTemperature()  { return targetTemperature; }
double BasicSmartThermoA::getCurrentTemperature() { return currentTemperature; }

void BasicSmartThermoA::setMode(ThermoMode m) {
    mode = m;
    cout << "[BasicSmartThermoA] Mode set to " << (int)m << endl;
}

ThermoMode BasicSmartThermoA::getMode() { return mode; }

void BasicSmartThermoA::turnOn() {
    status = DeviceStatus::ON;
    cout << "[BasicSmartThermoA] " << name << " turned ON" << endl;
}

void BasicSmartThermoA::turnOff() {
    status = DeviceStatus::OFF;
    cout << "[BasicSmartThermoA] " << name << " turned OFF" << endl;
}

string  BasicSmartThermoA::getId() { return id; }
string  BasicSmartThermoA::getName() { return name; }
DeviceStatus BasicSmartThermoA::getStatus() { return status; }
