#pragma once
#include <string>
#include "AbstractSmartLight.h"
#include "AbstractSmartThermostat.h"
#include "AbstractSmartCamera.h"
#include "AbstractDoorLock.h"
#include "AbstractMotionSen.h"

using namespace std;

class SmartDeviceFactory {
public:
    virtual ~SmartDeviceFactory() = default;

    virtual AbstractSmartLight* createLight(const string& type) = 0;
    virtual AbstractSmartThermostat* createThermostat(const string& type) = 0;
    virtual AbstractSmartCamera* createCamera(const string& type) = 0;
    virtual AbstractDoorLock* createDoorLock() = 0;
    virtual AbstractMotionSen* createMotionSensor() = 0;
};
