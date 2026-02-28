#include "../../Headers/Hub/SmartHomeHub.h"
#include <algorithm>
#include <iostream>
using namespace std;

SmartHomeHub::SmartHomeHub(SmartDeviceFactory* factory)
    : factory(factory), currentMode(nullptr) {}

SmartHomeHub::~SmartHomeHub() {
    for (auto* d : devices) delete d;
    devices.clear();
}

SmartDevice* SmartHomeHub::addDevice(const string& type, const string& zone) {
    SmartDevice* device = nullptr;
    // Use factory to create the device based on type -> 
    device = new SmartDevice("dev-" + to_string(devices.size() + 1), type, "Generic");
    device->setLocation(zone);
    devices.push_back(device);
    devicesByZone[zone].push_back(device);
    cout << "[SmartHomeHub] Added device: " << type << " in zone: " << zone << endl;
    return device;
}

void SmartHomeHub::removeDevice(const string& deviceId) {
    auto it = find_if(devices.begin(), devices.end(),
        [&deviceId](SmartDevice* d) { return d->getId() == deviceId; });
    if (it != devices.end()) {
        SmartDevice* d = *it;
        for (auto& zone : devicesByZone) {
            auto& vec = zone.second;
            vec.erase(remove(vec.begin(), vec.end(), d), vec.end());
        }
        devices.erase(it);
        delete d;
        cout << "[SmartHomeHub] Removed device: " << deviceId << endl;
    }
}

void SmartHomeHub::controlDevice(const string& deviceId, const string& action) {
    for (auto* d : devices) {
        if (d->getId() == deviceId) {
            if (action == "ON")  d->turnOn();
            else if (action == "OFF") d->turnOff();
            cout << "[SmartHomeHub] Device " << deviceId << " action: " << action << endl;
            return;
        }
    }
    cout << "[SmartHomeHub] Device not found: " << deviceId << endl;
}

void SmartHomeHub::executeAutomation(Command* command) {
    if (command) {
        command->execute();
        cout << "[SmartHomeHub] Automation command executed" << endl;
    }
}

void SmartHomeHub::setMode(AutomationModeStrategy* mode) {
    currentMode = mode;
    if (currentMode) {
        currentMode->applyMode(this);
        cout << "[SmartHomeHub] Mode set to: " << currentMode->getModeName() << endl;
    }
}

vector<SmartDevice*> SmartHomeHub::getDevicesByZone(const string& zone) {
    if (devicesByZone.count(zone)) return devicesByZone[zone];
    return {};
}

vector<SmartDevice*>& SmartHomeHub::getAllDevices() {
    return devices;
}
