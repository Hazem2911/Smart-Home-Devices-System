#include "../../Headers/Factory/PremiumWiredCamera.h"
#include <iostream>
using namespace std;

PremiumWiredCamera::PremiumWiredCamera(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), recording(false), nightVisionEnabled(false), status(DeviceStatus::OFF) {}

void PremiumWiredCamera::startRecording() {
    recording = true;
    cout << "[PremiumWiredCamera] " << name << " started recording" << endl;
}

void PremiumWiredCamera::stopRecording() {
    recording = false;
    cout << "[PremiumWiredCamera] " << name << " stopped recording" << endl;
}

void PremiumWiredCamera::enableNightVision() {
    nightVisionEnabled = true;
    cout << "[PremiumWiredCamera] Night vision enabled" << endl;
}

void PremiumWiredCamera::disableNightVision() {
    nightVisionEnabled = false;
    cout << "[PremiumWiredCamera] Night vision disabled" << endl;
}

bool PremiumWiredCamera::isRecording() { return recording; }

void PremiumWiredCamera::turnOn() {
    status = DeviceStatus::ON;
    cout << "[PremiumWiredCamera] " << name << " turned ON" << endl;
}

void PremiumWiredCamera::turnOff() {
    status = DeviceStatus::OFF;
    recording = false;
    cout << "[PremiumWiredCamera] " << name << " turned OFF" << endl;
}

string  PremiumWiredCamera::getId()     { return id; }
string  PremiumWiredCamera::getName()   { return name; }
DeviceStatus PremiumWiredCamera::getStatus() { return status; }
