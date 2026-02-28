#include "../../Headers/Command/TurnLightONComm.h"
#include "../../Headers/Composite/SmartDevice.h"
#include <iostream>
using namespace std;

TurnLightONComm::TurnLightONComm(SmartDevice* dev) : device(dev) {}

void TurnLightONComm::execute() {
    if (device) {
        device->turnOn();
        cout << "[TurnLightONComm] Turned ON: " << device->getName() << endl;
    }
}

void TurnLightONComm::undo() {
    if (device) {
        device->turnOff();
        cout << "[TurnLightONComm] Undo - Turned OFF: " << device->getName() << endl;
    }
}
