#pragma once
#include <string>
using namespace std;

class SmartDevice;

class DeviceState {
public:
    virtual ~DeviceState() = default;
    virtual void turnOn(SmartDevice* device) = 0;
    virtual void turnOff(SmartDevice* device) = 0;
    virtual void dim(SmartDevice* device, int level) = 0;
    virtual string getStateName() = 0;
};
