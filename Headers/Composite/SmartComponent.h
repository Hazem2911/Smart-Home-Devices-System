#pragma once
#include <string>
#include "../Common/Types.h"

using namespace std;

class SmartComponent {
public:
    virtual ~SmartComponent() = default;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getName() = 0;
    virtual string getId() = 0;
    virtual DeviceStatus getStatus() = 0;
};
