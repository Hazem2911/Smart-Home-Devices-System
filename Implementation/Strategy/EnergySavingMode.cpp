#include "../../Headers/Strategy/EnergySavingMode.h"
#include "../../Headers/Hub/SmartHomeHub.h"
#include <iostream>
using namespace std;

EnergySavingMode::EnergySavingMode(int maxDevices, int shutdownDelay)
    : maxAllowedDevices(maxDevices), autoShutdownDelay(shutdownDelay) {}

void EnergySavingMode::applyMode(SmartHomeHub* hub) {
    cout << "[EnergySavingMode] Applying energy saving mode. Max devices: "
              << maxAllowedDevices << ", Shutdown delay: " << autoShutdownDelay << "s" << endl;
    if (hub) {
        int count = 0;
        for (auto* device : hub->getAllDevices()) {
            if (count >= maxAllowedDevices) {
                device->turnOff();
            }
            count++;
        }
    }
}

string EnergySavingMode::getModeName() {
    return "EnergySavingMode";
}
