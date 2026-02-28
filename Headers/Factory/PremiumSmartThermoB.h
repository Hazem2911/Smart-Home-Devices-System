#pragma once
#include <string>
#include "../Common/Types.h"
#include "AbstractSmartThermostat.h"

using namespace std;

class PremiumSmartThermoB : public AbstractSmartThermostat {
private:
    string id;
    string name;
    string brand;
    double currentTemperature;
    double targetTemperature;
    ThermoMode mode;
    DeviceStatus status;

public:
    PremiumSmartThermoB(const string& id, const string& name, const string& brand);

    void setTargetTemperature(double temp) override;
    double getTargetTemperature() override;
    double getCurrentTemperature() override;
    void setMode(ThermoMode mode) override;
    ThermoMode getMode() override;
    void turnOn() override;
    void turnOff() override;
    string getId() override;
    string getName() override;
    DeviceStatus getStatus() override;
};
