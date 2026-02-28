#include "../../Headers/Adapter/LegacyDevice.h"
#include <iostream>
using namespace std;

LegacyDevice::LegacyDevice(const string& externalId, const string& vendorName, const string& protocolType)
    : externalId(externalId), vendorName(vendorName), protocolType(protocolType),
      isConnected(false), rawState("OFF") {}

void LegacyDevice::connect() {
    isConnected = true;
    cout << "[LegacyDevice] " << vendorName << " connected via " << protocolType << endl;
}

void LegacyDevice::disconnect() {
    isConnected = false;
    cout << "[LegacyDevice] " << vendorName << " disconnected" << endl;
}

void LegacyDevice::sendCommand(const string& cmd) {
    if (isConnected) {
        rawState = cmd;
        cout << "[LegacyDevice] Command sent: " << cmd << endl;
    } else {
        cout << "[LegacyDevice] Cannot send command - device not connected" << endl;
    }
}

string LegacyDevice::getStatus() {
    return rawState;
}
