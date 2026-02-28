#pragma once
#include <string>
using namespace std;

class SmartHomeHub;

class AutomationModeStrategy {
public:
    virtual ~AutomationModeStrategy() = default;
    virtual void applyMode(SmartHomeHub* hub) = 0;
    virtual string getModeName() = 0;
};
