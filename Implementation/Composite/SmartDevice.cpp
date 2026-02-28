#include "../../Headers/Composite/SmartDevice.h"
#include "../../Headers/State/LightOffState.h"
#include <algorithm>
#include <iostream>

using namespace std;

SmartDevice::SmartDevice(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), status(DeviceStatus::OFF), location(""),
      currentState(new LightOffState()) {}

SmartDevice::~SmartDevice() {
    delete currentState;
}

void SmartDevice::turnOn() {
    status = DeviceStatus::ON;
    if (currentState) currentState->turnOn(this);
    notify();
}

void SmartDevice::turnOff() {
    status = DeviceStatus::OFF;
    if (currentState) currentState->turnOff(this);
    notify();
}

void SmartDevice::dim(int level) {
    if (currentState) currentState->dim(this, level);
    notify();
}

string SmartDevice::getId() { return id; }
string SmartDevice::getName() { return name; }
string SmartDevice::getBrand() const { return brand; }
DeviceStatus SmartDevice::getStatus() { return status; }

void SmartDevice::setLocation(const string& loc) { location = loc; }
string SmartDevice::getLocation() const { return location; }

void SmartDevice::attach(Observer* o) {
    observers.push_back(o);
}

void SmartDevice::detach(Observer* o) {
    observers.remove(o);
}

void SmartDevice::notify() {
    for (auto* obs : observers) {
        obs->update(this);
    }
}

void SmartDevice::setState(DeviceState* state) {
    delete currentState;
    currentState = state;
}

DeviceState* SmartDevice::getCurrentState() const {
    return currentState;
}
