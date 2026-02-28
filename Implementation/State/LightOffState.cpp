#include "../../Headers/State/LightOffState.h"
#include "../../Headers/State/LightOnState.h"
#include "../../Headers/Composite/SmartDevice.h"
#include <iostream>
using namespace std;

void LightOffState::turnOn(SmartDevice* device) {
    cout << "[LightOffState] Turning ON light: " << device->getName() << endl;
    device->setState(new LightOnState());
}

void LightOffState::turnOff(SmartDevice* device) {
    cout << "[LightOffState] Light is already OFF." << endl;
}

void LightOffState::dim(SmartDevice* device, int level) {
    cout << "[LightOffState] Cannot dim a light that is OFF." << endl;
}

string LightOffState::getStateName() {
    return "LightOffState";
}
