#pragma once

class SmartDevice;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(SmartDevice* device) = 0;
};
