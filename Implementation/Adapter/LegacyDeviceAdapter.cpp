#include "../../Headers/Adapter/LegacyDeviceAdapter.h"
#include <iostream>
using namespace std;

LegacyDeviceAdapter::LegacyDeviceAdapter(const string& id, const string& name,
                                         LegacyDevice* device, const string& adapterVersion)
    : SmartDevice(id, name, "LegacyBrand"), externalDevice(device),
      adapterVersion(adapterVersion), protocolSynced(false) {
    if (externalDevice) {
        externalDevice->connect();
        protocolSynced = true;
    }
}

LegacyDeviceAdapter::~LegacyDeviceAdapter() {
    if (externalDevice) {
        externalDevice->disconnect();
    }
}

void LegacyDeviceAdapter::turnOn() {
    string cmd = translateCommand("TURN_ON");
    if (externalDevice) externalDevice->sendCommand(cmd);
    SmartDevice::turnOn();
    cout << "[LegacyDeviceAdapter] Turned ON via adapter v" << adapterVersion << endl;
}

void LegacyDeviceAdapter::turnOff() {
    string cmd = translateCommand("TURN_OFF");
    if (externalDevice) externalDevice->sendCommand(cmd);
    SmartDevice::turnOff();
    cout << "[LegacyDeviceAdapter] Turned OFF via adapter v" << adapterVersion << endl;
}

DeviceStatus LegacyDeviceAdapter::getStatus() {
    return SmartDevice::getStatus();
}

void LegacyDeviceAdapter::control() {
    cout << "[LegacyDeviceAdapter] Controlling legacy device..." << endl;
    if (externalDevice) {
        cout << "Device state: " << externalDevice->getStatus() << endl;
    }
}

string LegacyDeviceAdapter::translateCommand(const string& cmd) {
    if (cmd == "TURN_ON")  return "PWR=1";
    if (cmd == "TURN_OFF") return "PWR=0";
    return cmd;
}
