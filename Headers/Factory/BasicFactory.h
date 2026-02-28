#pragma once
#include "SmartDeviceFactory.h"

using namespace std;

class BasicFactory : public SmartDeviceFactory {
public:
    AbstractSmartLight* createLight(const string& type) override;
    AbstractSmartThermostat* createThermostat(const string& type) override;
    AbstractSmartCamera* createCamera(const string& type) override;
    AbstractDoorLock* createDoorLock() override;
    AbstractMotionSen* createMotionSensor() override;
};
