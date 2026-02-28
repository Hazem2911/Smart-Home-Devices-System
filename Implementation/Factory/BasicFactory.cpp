#include "../../Headers/Factory/BasicFactory.h"
#include "../../Headers/Factory/BasicLedLight.h"
#include "../../Headers/Factory/BasicHalLight.h"
#include "../../Headers/Factory/BasicSmartThermoA.h"
#include "../../Headers/Factory/BasicSmartThermoB.h"
#include "../../Headers/Factory/BasicWiredCamera.h"
#include "../../Headers/Factory/BasicWirelessCamera.h"
#include <stdexcept>
#include <iostream>
using namespace std;

AbstractSmartLight* BasicFactory::createLight(const string& type) {
    if (type == "LED") {
        cout << "[BasicFactory] Creating BasicLedLight" << endl;
        return new BasicLedLight("BLed-001", "Basic LED", "BrandY");
    } else if (type == "HALOGEN") {
        cout << "[BasicFactory] Creating BasicHalLight" << endl;
        return new BasicHalLight("BHal-001", "Basic Halogen", "BrandY");
    }
    throw invalid_argument("Unknown light type: " + type);
}

AbstractSmartThermostat* BasicFactory::createThermostat(const string& type) {
    if (type == "A") {
        cout << "[BasicFactory] Creating BasicSmartThermoA" << endl;
        return new BasicSmartThermoA("BThA-001", "Basic Thermo A", "BrandY");
    } else if (type == "B") {
        cout << "[BasicFactory] Creating BasicSmartThermoB" << endl;
        return new BasicSmartThermoB("BThB-001", "Basic Thermo B", "BrandY");
    }
    throw invalid_argument("Unknown thermostat type: " + type);
}

AbstractSmartCamera* BasicFactory::createCamera(const string& type) {
    if (type == "WIRED") {
        cout << "[BasicFactory] Creating BasicWiredCamera" << endl;
        return new BasicWiredCamera("BWC-001", "Basic Wired Camera", "BrandY");
    } else if (type == "WIRELESS") {
        cout << "[BasicFactory] Creating BasicWirelessCamera" << endl;
        return new BasicWirelessCamera("BWLC-001", "Basic Wireless Camera", "BrandY");
    }
    throw invalid_argument("Unknown camera type: " + type);
}

AbstractDoorLock* BasicFactory::createDoorLock() {
    cout << "[BasicFactory] createDoorLock() - Not yet implemented for basic tier" << endl;
    return nullptr;
}

AbstractMotionSen* BasicFactory::createMotionSensor() {
    cout << "[BasicFactory] createMotionSensor() - Not yet implemented for basic tier" << endl;
    return nullptr;
}
