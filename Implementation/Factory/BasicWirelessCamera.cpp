#include "../../Headers/Factory/BasicWirelessCamera.h"
#include <iostream>
using namespace std;

BasicWirelessCamera::BasicWirelessCamera(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), recording(false), nightVisionEnabled(false), status(DeviceStatus::OFF) {}

void BasicWirelessCamera::startRecording() {
    recording = true;
    cout << "[BasicWirelessCamera] " << name << " started recording" << endl;
}

void BasicWirelessCamera::stopRecording() {
    recording = false;
    cout << "[BasicWirelessCamera] " << name << " stopped recording" << endl;
}

void BasicWirelessCamera::enableNightVision() {
    nightVisionEnabled = true;
    cout << "[BasicWirelessCamera] Night vision enabled" << endl;
}

void BasicWirelessCamera::disableNightVision() {
    nightVisionEnabled = false;
    cout << "[BasicWirelessCamera] Night vision disabled" << endl;
}

bool BasicWirelessCamera::isRecording() { return recording; }

void BasicWirelessCamera::turnOn() {
    status = DeviceStatus::ON;
    cout << "[BasicWirelessCamera] " << name << " turned ON" << endl;
}

void BasicWirelessCamera::turnOff() {
    status = DeviceStatus::OFF;
    recording = false;
    cout << "[BasicWirelessCamera] " << name << " turned OFF" << endl;
}

string  BasicWirelessCamera::getId()     { return id; }
string  BasicWirelessCamera::getName()   { return name; }
DeviceStatus BasicWirelessCamera::getStatus() { return status; }
