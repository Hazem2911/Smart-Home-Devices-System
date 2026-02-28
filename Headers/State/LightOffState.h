#pragma once
#include <string>
#include "DeviceState.h"
using namespace std;

class LightOffState : public DeviceState {
public:
    void turnOn(SmartDevice* device) override;
    void turnOff(SmartDevice* device) override;
    void dim(SmartDevice* device, int level) override;
    string getStateName() override;
};
