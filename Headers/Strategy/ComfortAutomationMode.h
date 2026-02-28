#pragma once
#include <string>
#include "AutomationModeStrategy.h"
using namespace std;

class ComfortAutomationMode : public AutomationModeStrategy {
private:
    int temperatureLevel;
    int brightnessLevel;

public:
    ComfortAutomationMode(int tempLevel = 22, int brightLevel = 80);

    void applyMode(SmartHomeHub* hub) override;
    string getModeName() override;
};
