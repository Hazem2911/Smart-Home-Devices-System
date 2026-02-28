#include "../../Headers/Factory/PremiumSmartThermoB.h"
#include <iostream>
using namespace std;

PremiumSmartThermoB::PremiumSmartThermoB(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), currentTemperature(20.0), targetTemperature(22.0),
      mode(ThermoMode::AUTO), status(DeviceStatus::OFF) {}

void PremiumSmartThermoB::setTargetTemperature(double temp) {
    targetTemperature = temp;
    cout << "[PremiumSmartThermoB] Target temperature set to " << temp << endl;
}

double PremiumSmartThermoB::getTargetTemperature()  { return targetTemperature; }
double PremiumSmartThermoB::getCurrentTemperature() { return currentTemperature; }

void PremiumSmartThermoB::setMode(ThermoMode m) {
    mode = m;
    cout << "[PremiumSmartThermoB] Mode set to " << (int)m << endl;
}

ThermoMode PremiumSmartThermoB::getMode() { return mode; }

void PremiumSmartThermoB::turnOn() {
    status = DeviceStatus::ON;
    cout << "[PremiumSmartThermoB] " << name << " turned ON" << endl;
}

void PremiumSmartThermoB::turnOff() {
    status = DeviceStatus::OFF;
    cout << "[PremiumSmartThermoB] " << name << " turned OFF" << endl;
}

string  PremiumSmartThermoB::getId()     { return id; }
string  PremiumSmartThermoB::getName()   { return name; }
DeviceStatus PremiumSmartThermoB::getStatus() { return status; }
