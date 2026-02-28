#include "../../Headers/Strategy/ComfortAutomationMode.h"
#include "../../Headers/Hub/SmartHomeHub.h"
#include <iostream>
using namespace std;

ComfortAutomationMode::ComfortAutomationMode(int tempLevel, int brightLevel)
    : temperatureLevel(tempLevel), brightnessLevel(brightLevel) {}

void ComfortAutomationMode::applyMode(SmartHomeHub* hub) {
    cout << "[ComfortAutomationMode] Applying comfort mode. Temp: "
              << temperatureLevel << ", Brightness: " << brightnessLevel << endl;
    if (hub) {
        for (auto* device : hub->getAllDevices()) {
            device->turnOn();
        }
    }
}

string ComfortAutomationMode::getModeName() {
    return "ComfortAutomationMode";
}
