#include "../../Headers/Factory/PremiumFactory.h"
#include "../../Headers/Factory/PremiumLedLight.h"
#include "../../Headers/Factory/PremiumHalogenLight.h"
#include "../../Headers/Factory/PremiumSmartThermoA.h"
#include "../../Headers/Factory/PremiumSmartThermoB.h"
#include "../../Headers/Factory/PremiumWiredCamera.h"
#include "../../Headers/Factory/PremiumWirelessCamera.h"
#include <stdexcept>
#include <iostream>
using namespace std;

AbstractSmartLight* PremiumFactory::createLight(const string& type) {
    if (type == "LED") {
        cout << "[PremiumFactory] Creating PremiumLedLight" << endl;
        return new PremiumLedLight("PLed-001", "Premium LED", "BrandX");
    } else if (type == "HALOGEN") {
        cout << "[PremiumFactory] Creating PremiumHalogenLight" << endl;
        return new PremiumHalogenLight("PHal-001", "Premium Halogen", "BrandX");
    }
    throw invalid_argument("Unknown light type: " + type);
}

AbstractSmartThermostat* PremiumFactory::createThermostat(const string& type) {
    if (type == "A") {
        cout << "[PremiumFactory] Creating PremiumSmartThermoA" << endl;
        return new PremiumSmartThermoA("PThA-001", "Premium Thermo A", "BrandX");
    } else if (type == "B") {
        cout << "[PremiumFactory] Creating PremiumSmartThermoB" << endl;
        return new PremiumSmartThermoB("PThB-001", "Premium Thermo B", "BrandX");
    }
    throw invalid_argument("Unknown thermostat type: " + type);
}

AbstractSmartCamera* PremiumFactory::createCamera(const string& type) {
    if (type == "WIRED") {
        cout << "[PremiumFactory] Creating PremiumWiredCamera" << endl;
        return new PremiumWiredCamera("PWC-001", "Premium Wired Camera", "BrandX");
    } else if (type == "WIRELESS") {
        cout << "[PremiumFactory] Creating PremiumWirelessCamera" << endl;
        return new PremiumWirelessCamera("PWLC-001", "Premium Wireless Camera", "BrandX");
    }
    throw invalid_argument("Unknown camera type: " + type);
}

AbstractDoorLock* PremiumFactory::createDoorLock() {
    cout << "[PremiumFactory] createDoorLock() - Not yet implemented for premium tier" << endl;
    return nullptr;
}

AbstractMotionSen* PremiumFactory::createMotionSensor() {
    cout << "[PremiumFactory] createMotionSensor() - Not yet implemented for premium tier" << endl;
    return nullptr;
}
