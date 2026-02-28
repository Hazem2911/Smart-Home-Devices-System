#include "../../Headers/Factory/PremiumLedLight.h"
#include <iostream>
using namespace std;

PremiumLedLight::PremiumLedLight(const string& id, const string& name, const string& brand)
    : id(id), name(name), brand(brand), brightness(100), state(LightState::OFF) {}

void PremiumLedLight::turnOn() {
    state = LightState::ON;
    cout << "[PremiumLedLight] " << name << " turned ON at brightness " << brightness << endl;
}

void PremiumLedLight::turnOff() {
    state = LightState::OFF;
    cout << "[PremiumLedLight] " << name << " turned OFF" << endl;
}

bool PremiumLedLight::adjustbrightness(int level) {
    brightness = level;
    state = LightState::DIMMED;
    cout << "[PremiumLedLight] " << name << " brightness set to " << level << endl;
    return true;
}

string PremiumLedLight::getType()  { return "PremiumLedLight"; }

void PremiumLedLight::setBrightness(int level) { brightness = level; }
int  PremiumLedLight::getBrightness()          { return brightness;  }
LightState PremiumLedLight::getLightState()    { return state;        }

string  PremiumLedLight::getId()     { return id;    }
string  PremiumLedLight::getName()   { return name;  }
string  PremiumLedLight::getBrand()  { return brand; }

DeviceStatus PremiumLedLight::getStatus() {
    return (state == LightState::OFF) ? DeviceStatus::OFF : DeviceStatus::ON;
}
