#pragma once
#include <string>
#include <vector>
#include <map>

#include "Headers/Composite/SmartDevice.h"
#include "../Factory/SmartDeviceFactory.h"
#include "../Strategy/AutomationModeStrategy.h"
#include "../Command/Command.h"

using namespace std;

class SmartHomeHub {
private:
    vector<SmartDevice*> devices;
    map<string, vector<SmartDevice*>> devicesByZone;
    SmartDeviceFactory* factory;
    AutomationModeStrategy* currentMode;

public:
    SmartHomeHub(SmartDeviceFactory* factory);
    ~SmartHomeHub();

    SmartDevice* addDevice(const string& type, const string& zone);
    void removeDevice(const string& deviceId);
    void controlDevice(const string& deviceId, const string& action);
    void executeAutomation(Command* command);
    void setMode(AutomationModeStrategy* mode);
    vector<SmartDevice*> getDevicesByZone(const string& zone);

    vector<SmartDevice*>& getAllDevices();
};
