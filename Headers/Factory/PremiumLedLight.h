#pragma once
#include <string>
#include "../Common/Types.h"
#include "AbstractSmartLight.h"

using namespace std;

class PremiumLedLight : public AbstractSmartLight {
private:
    string id;
    string name;
    string brand;
    int brightness;
    LightState state;

public:
    PremiumLedLight(const string& id, const string& name, const string& brand);

    void turnOn() override;
    void turnOff() override;
    bool adjustbrightness(int level) override;
    string getType() override;
    void setBrightness(int level);
    int getBrightness();
    LightState getLightState();
    string getId() override;
    string getName() override;
    string getBrand();
    DeviceStatus getStatus() override;
};
