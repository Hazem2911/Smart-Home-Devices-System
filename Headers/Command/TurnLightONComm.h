#pragma once
#include <string>
#include "../Command/Command.h"
using namespace std;

class SmartDevice;

class TurnLightONComm : public Command {
    SmartDevice* device;

public:
    TurnLightONComm(SmartDevice* dev);
    void execute() override;
    void undo() override;
};
