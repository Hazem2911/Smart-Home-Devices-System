#pragma once
#include <string>
#include "AutomationModeStrategy.h"
using namespace std;

class EnergySavingMode : public AutomationModeStrategy {
private:
    int maxAllowedDevices;
    int autoShutdownDelay;

public:
    EnergySavingMode(int maxDevices = 5, int shutdownDelay = 30);

    void applyMode(SmartHomeHub* hub) override;
    string getModeName() override;
};
