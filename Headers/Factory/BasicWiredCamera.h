#pragma once
#include <string>
#include "../Common/Types.h"
#include "AbstractSmartCamera.h"
using namespace std;

class BasicWiredCamera : public AbstractSmartCamera {
private:
    string id;
    string name;
    string brand;
    bool recording;
    bool nightVisionEnabled;
    DeviceStatus status;

public:
    BasicWiredCamera(const string& id, const string& name, const string& brand);

    void startRecording() override;
    void stopRecording() override;
    void enableNightVision() override;
    void disableNightVision() override;
    bool isRecording() override;
    void turnOn() override;
    void turnOff() override;
    string getId() override;
    string getName() override;
    DeviceStatus getStatus() override;
};
