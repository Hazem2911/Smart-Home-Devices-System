#pragma once
#include <string>
#include <vector>
#include "SmartComponent.h"

using namespace std;

class DeviceComposite : public SmartComponent {
private:
    string groupId;
    string groupName;
    string groupType;   // Floor / Room / Functional
    vector<SmartComponent*> children;

public:
    DeviceComposite(const string& id, const string& name, const string& type);
    virtual ~DeviceComposite();

    void add(SmartComponent* component);
    void rem(SmartComponent* component);
    vector<SmartComponent*> getChildren();

    void turnOn() override;
    void turnOff() override;
    string getName() override;
    string getId() override;
    DeviceStatus getStatus() override;
};
