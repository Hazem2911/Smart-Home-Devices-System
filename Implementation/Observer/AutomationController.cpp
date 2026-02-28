#include "../../Headers/Observer/AutomationController.h"
#include "../../Headers/Composite/SmartDevice.h"
#include <iostream>
#include <algorithm>
using namespace std;

AutomationController::AutomationController() {}

AutomationController::~AutomationController() {
    Histiorycommands.clear();
}

void AutomationController::update(SmartDevice* device) {
    if (!device) return;
    string status = (device->getStatus() == DeviceStatus::ON) ? "ON" : "OFF";
    cout << "[AutomationController] Device updated: " << device->getName()
         << " Status: " << status << endl;
}

void AutomationController::addCommand(Command* cmd) {
    if (cmd) {
        Histiorycommands.push_back(cmd);
    }
}

void AutomationController::executeCommand(Command* cmd) {
    if (cmd) {
        cmd->execute();
        Histiorycommands.push_back(cmd);
    }
}
