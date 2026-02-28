#pragma once
#include <string>
#include "../Common/Types.h"
#include "AbstractSmartLight.h"

using namespace std;

class PremiumHalogenLight : public AbstractSmartLight {
private:
    string id;
    string name;
    string brand;
    DeviceStatus status;
public:
    PremiumHalogenLight(const string& id, const string& name, const string& brand);

    void turnOn() override;
    void turnOff() override;
    bool adjustbrightness(int level) override;
    string getType() override;
    string getId() override;
    string getName() override;
    DeviceStatus getStatus() override;
};
