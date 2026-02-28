#pragma once
#include <string>
#include "../Common/Types.h"
#include "../Composite/SmartComponent.h"

using namespace std;

class AbstractSmartLight : public SmartComponent {
public:
    virtual ~AbstractSmartLight() = default;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool adjustbrightness(int level) = 0;
    virtual string getType() = 0;
};
