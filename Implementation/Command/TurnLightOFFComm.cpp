#include "../../Headers/Command/TurnLightOFFComm.h"
#include "../../Headers/Composite/SmartDevice.h"
#include <iostream>
using namespace std;

TurnLightOFFComm::TurnLightOFFComm(SmartDevice* dev) : device(dev) {}

void TurnLightOFFComm::execute() {
    if (device) {
        device->turnOff();
        cout << "[TurnLightOFFComm] Turned OFF: " << device->getName() << endl;
    }
}

void TurnLightOFFComm::undo() {
    if (device) {
        device->turnOn();
        cout << "[TurnLightOFFComm] Undo - Turned ON: " << device->getName() << endl;
    }
}
