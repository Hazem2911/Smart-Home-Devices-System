#pragma once
#include "../Composite/SmartComponent.h"

using namespace std;

class AbstractMotionSen : public SmartComponent {
public:
    virtual ~AbstractMotionSen() = default;

    virtual bool detectMotion() = 0;
    virtual void setSensitivity(int level) = 0;
    virtual int getSensitivity() = 0;
};
