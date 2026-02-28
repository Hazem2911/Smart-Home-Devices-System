#include "../../Headers/Composite/DeviceComposite.h"
#include <algorithm>
#include <iostream>

using namespace std;

DeviceComposite::DeviceComposite(const string& id, const string& name, const string& type)
    : groupId(id), groupName(name), groupType(type) {}

DeviceComposite::~DeviceComposite() {}

void DeviceComposite::add(SmartComponent* component) {
    if (component) children.push_back(component);
}

void DeviceComposite::rem(SmartComponent* component) {
    children.erase(remove(children.begin(), children.end(), component), children.end());
}

vector<SmartComponent*> DeviceComposite::getChildren() {
    return children;
}

void DeviceComposite::turnOn() {
    cout << "[DeviceComposite] Turning ON group: " << groupName << endl;
    for (auto* child : children) child->turnOn();
}

void DeviceComposite::turnOff() {
    cout << "[DeviceComposite] Turning OFF group: " << groupName << endl;
    for (auto* child : children) child->turnOff();
}

string DeviceComposite::getName() { return groupName; }
string DeviceComposite::getId()   { return groupId;   }

DeviceStatus DeviceComposite::getStatus() {
    return DeviceStatus::ON;
}
