#pragma once
#include <string>
#include "../Common/Types.h"
#include "../Composite/SmartComponent.h"

using namespace std;

class AbstractSmartThermostat : public SmartComponent {
public:
    virtual ~AbstractSmartThermostat() = default;

    virtual void setTargetTemperature(double temp) = 0;
    virtual double getTargetTemperature() = 0;
    virtual double getCurrentTemperature() = 0;
    virtual void setMode(ThermoMode mode) = 0;
    virtual ThermoMode getMode() = 0;
};
