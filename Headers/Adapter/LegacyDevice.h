#pragma once
#include <string>
using namespace std;

class LegacyDevice {
private:
    string externalId;
    string vendorName;
    string protocolType;
    bool isConnected;
    string rawState;

public:
    LegacyDevice(const string& externalId, const string& vendorName, const string& protocolType);

    void connect();
    void disconnect();
    void sendCommand(const string& cmd);
    string getStatus();
};
