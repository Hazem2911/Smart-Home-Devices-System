#include "../../Headers/State/LightDimmedState.h"
#include "../../Headers/State/LightOnState.h"
#include "../../Headers/State/LightOffState.h"
#include "../../Headers/Composite/SmartDevice.h"
#include <iostream>
using namespace std;

LightDimmedState::LightDimmedState(int brightness) : brightnessLevel(brightness) {}

void LightDimmedState::turnOn(SmartDevice* device) {
    cout << "[LightDimmedState] Turning ON (full) light: " << device->getName() << endl;
    device->setState(new LightOnState());
}

void LightDimmedState::turnOff(SmartDevice* device) {
    cout << "[LightDimmedState] Turning OFF light: " << device->getName() << endl;
    device->setState(new LightOffState());
}

void LightDimmedState::dim(SmartDevice* device, int level) {
    brightnessLevel = level;
    cout << "[LightDimmedState] Changing dim level to: " << level << endl;
}

string LightDimmedState::getStateName() {
    return "LightDimmedState";
}
