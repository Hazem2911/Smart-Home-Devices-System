#include "../../Headers/State/LightOnState.h"
#include "../../Headers/State/LightOffState.h"
#include "../../Headers/State/LightDimmedState.h"
#include "../../Headers/Composite/SmartDevice.h"
#include <iostream>
using namespace std;

LightOnState::LightOnState(int brightness) : brightnessLevel(brightness) {}

void LightOnState::turnOn(SmartDevice* device) {
    cout << "[LightOnState] Light is already ON." << endl;
}

void LightOnState::turnOff(SmartDevice* device) {
    cout << "[LightOnState] Turning OFF light: " << device->getName() << endl;
    device->setState(new LightOffState());
}

void LightOnState::dim(SmartDevice* device, int level) {
    cout << "[LightOnState] Dimming light: " << device->getName() << " to level " << level << endl;
    device->setState(new LightDimmedState(level));
}

string LightOnState::getStateName() {
    return "LightOnState";
}
