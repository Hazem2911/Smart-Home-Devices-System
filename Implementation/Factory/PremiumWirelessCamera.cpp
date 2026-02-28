#include "../../Headers/Factory/PremiumWirelessCamera.h"
#include <iostream>
using namespace std;

PremiumWirelessCamera::PremiumWirelessCamera(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), recording(false), nightVisionEnabled(false), status(DeviceStatus::OFF) {}

void PremiumWirelessCamera::startRecording() {
    recording = true;
    cout << "[PremiumWirelessCamera] " << name << " started recording" << endl;
}

void PremiumWirelessCamera::stopRecording() {
    recording = false;
    cout << "[PremiumWirelessCamera] " << name << " stopped recording" << endl;
}

void PremiumWirelessCamera::enableNightVision() {
    nightVisionEnabled = true;
    cout << "[PremiumWirelessCamera] Night vision enabled" << endl;
}

void PremiumWirelessCamera::disableNightVision() {
    nightVisionEnabled = false;
    cout << "[PremiumWirelessCamera] Night vision disabled" << endl;
}

bool PremiumWirelessCamera::isRecording() {return recording;}

void PremiumWirelessCamera::turnOn() {
    status = DeviceStatus::ON;
    cout << "[PremiumWirelessCamera] " << name << " turned ON" << endl;
}

void PremiumWirelessCamera::turnOff() {
    status = DeviceStatus::OFF;
    recording = false;
    cout << "[PremiumWirelessCamera] " << name << " turned OFF" << endl;
}

string  PremiumWirelessCamera::getId() {return id;}
string  PremiumWirelessCamera::getName() {return name;}
DeviceStatus PremiumWirelessCamera::getStatus() {return status;}
