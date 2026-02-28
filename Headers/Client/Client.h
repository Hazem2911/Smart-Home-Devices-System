#pragma once
#include "../Hub/SmartHomeHub.h"
#include "../Observer/AutomationController.h"
using namespace std;

class Client {
private:
    SmartHomeHub* hub;
    AutomationController* controller;
public:
    Client();
    ~Client();
    void setupSystem();
    void run();
};
