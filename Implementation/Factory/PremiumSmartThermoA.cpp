#include "../../Headers/Factory/PremiumSmartThermoA.h"
#include <iostream>
using namespace std;

PremiumSmartThermoA::PremiumSmartThermoA(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), currentTemperature(20.0), targetTemperature(22.0),
      mode(ThermoMode::AUTO), status(DeviceStatus::OFF) {}

void PremiumSmartThermoA::setTargetTemperature(double temp) {
    targetTemperature = temp;
    cout << "[PremiumSmartThermoA] Target temperature set to " << temp << endl;
}

double PremiumSmartThermoA::getTargetTemperature() {return targetTemperature;}
double PremiumSmartThermoA::getCurrentTemperature() {return currentTemperature;}

void PremiumSmartThermoA::setMode(ThermoMode m) {
    mode = m;
    cout << "[PremiumSmartThermoA] Mode set to " << (int)m << endl;
}

ThermoMode PremiumSmartThermoA::getMode() {return mode;}

void PremiumSmartThermoA::turnOn() {
    status = DeviceStatus::ON;
    cout << "[PremiumSmartThermoA] " << name << " turned ON" << endl;
}

void PremiumSmartThermoA::turnOff() {
    status = DeviceStatus::OFF;
    cout << "[PremiumSmartThermoA] " << name << " turned OFF" << endl;
}

string  PremiumSmartThermoA::getId() {return id;}
string  PremiumSmartThermoA::getName() {return name;}
DeviceStatus PremiumSmartThermoA::getStatus() {return status;}
