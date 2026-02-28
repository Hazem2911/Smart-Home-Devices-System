#pragma once
#include <string>
#include <list>
#include "SmartComponent.h"
#include "../Observer/Subject.h"
#include "../State/DeviceState.h"

using namespace std;

class SmartDevice : public SmartComponent, public Subject {
private:
    string id;
    string name;
    string brand;
    DeviceStatus status;
    string location;
    list<Observer*> observers;
    DeviceState* currentState;

public:
    SmartDevice(const string& id, const string& name, const string& brand);
    virtual ~SmartDevice();

    void turnOn() override;
    void turnOff() override;
    void dim(int level);
    string getId() override;
    string getName() override;
    string getBrand() const;
    DeviceStatus getStatus() override;
    void setLocation(const string& loc);
    string getLocation() const;

    void attach(Observer* o) override;
    void detach(Observer* o) override;
    void notify() override;

    void setState(DeviceState* state);
    DeviceState* getCurrentState() const;
};
