#pragma once
#include <string>
#include "DeviceState.h"
using namespace std;

class LightOnState : public DeviceState {
private:
    int brightnessLevel;

public:
    LightOnState(int brightness = 100);

    void turnOn(SmartDevice* device) override;
    void turnOff(SmartDevice* device) override;
    void dim(SmartDevice* device, int level) override;
    string getStateName() override;
};
