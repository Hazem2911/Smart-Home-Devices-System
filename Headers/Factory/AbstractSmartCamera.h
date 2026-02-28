#pragma once
#include "../Composite/SmartComponent.h"

using namespace std;

class AbstractSmartCamera : public SmartComponent {
public:
    virtual ~AbstractSmartCamera() = default;

    virtual void startRecording() = 0;
    virtual void stopRecording() = 0;
    virtual void enableNightVision() = 0;
    virtual void disableNightVision() = 0;
    virtual bool isRecording() = 0;
};
