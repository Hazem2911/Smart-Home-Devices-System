#pragma once
#include <string>
#include "DeviceState.h"
using namespace std;

class LightDimmedState : public DeviceState {
private:
    int brightnessLevel;

public:
    LightDimmedState(int brightness = 50);

    void turnOn(SmartDevice* device) override;
    void turnOff(SmartDevice* device) override;
    void dim(SmartDevice* device, int level) override;
    string getStateName() override;
};
