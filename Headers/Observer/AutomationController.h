#pragma once
#include <string>
#include <list>
#include <vector>
#include "../Observer/Observer.h"
#include "../Observer/Subject.h"
#include "../Command/Command.h"
using namespace std;

class SmartDevice;

class AutomationController : public Observer {
private:
    list<SmartDevice*> monitoredDevices;
    vector<Command*> Histiorycommands;

public:
    AutomationController();
    ~AutomationController();

    void update(SmartDevice* device) override;
    void addCommand(Command* cmd);
    void executeCommand(Command* cmd);
};
