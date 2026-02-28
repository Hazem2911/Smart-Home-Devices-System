#pragma once
#include "../Composite/SmartComponent.h"

using namespace std;

class AbstractDoorLock : public SmartComponent {
public:
    virtual ~AbstractDoorLock() = default;

    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual bool isLocked() = 0;
};
