#pragma once
#include <string>
#include<iostream>
#include "../Command/Command.h"

using namespace std;

class SmartDevice;

class TurnLightOFFComm : public Command {
    SmartDevice* device;
    
public:
    TurnLightOFFComm(SmartDevice* dev);
    void execute() override;
    void undo() override;
};
