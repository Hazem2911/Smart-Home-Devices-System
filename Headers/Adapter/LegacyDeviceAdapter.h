#pragma once
#include <string>
#include "../Composite/SmartDevice.h"
#include "LegacyDevice.h"
using namespace std;

class LegacyDeviceAdapter : public SmartDevice {
private:
    LegacyDevice* externalDevice;
    string adapterVersion;
    bool protocolSynced;
    string translateCommand(const string& cmd);
public:
    LegacyDeviceAdapter(const string& id, const string& name, LegacyDevice* device,
                        const string& adapterVersion = "1.0");
    ~LegacyDeviceAdapter();

    void turnOn() override;
    void turnOff() override;
    DeviceStatus getStatus() override;
    void control();
};
