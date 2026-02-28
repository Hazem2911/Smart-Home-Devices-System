#include "../../Headers/Factory/BasicWiredCamera.h"
#include <iostream>
using namespace std;

BasicWiredCamera::BasicWiredCamera(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), recording(false), nightVisionEnabled(false), status(DeviceStatus::OFF) {}

void BasicWiredCamera::startRecording() {
    recording = true;
    cout << "[BasicWiredCamera] " << name << " started recording" << endl;
}

void BasicWiredCamera::stopRecording() {
    recording = false;
    cout << "[BasicWiredCamera] " << name << " stopped recording" << endl;
}

void BasicWiredCamera::enableNightVision() {
    nightVisionEnabled = true;
    cout << "[BasicWiredCamera] Night vision enabled" << endl;
}

void BasicWiredCamera::disableNightVision() {
    nightVisionEnabled = false;
    cout << "[BasicWiredCamera] Night vision disabled" << endl;
}

bool BasicWiredCamera::isRecording() { return recording; }

void BasicWiredCamera::turnOn() {
    status = DeviceStatus::ON;
    cout << "[BasicWiredCamera] " << name << " turned ON" << endl;
}

void BasicWiredCamera::turnOff() {
    status = DeviceStatus::OFF;
    recording = false;
    cout << "[BasicWiredCamera] " << name << " turned OFF" << endl;
}

string  BasicWiredCamera::getId() { return id; }
string  BasicWiredCamera::getName() { return name; }
DeviceStatus BasicWiredCamera::getStatus() { return status; }
