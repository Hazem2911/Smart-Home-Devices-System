#pragma once
#include <string>
#include "DeviceComposite.h"

using namespace std;

class RoomComposite : public DeviceComposite {
    string roomType;
public:

    RoomComposite(const string& id, const string& name, const string& roomType);
    string getRoomType();
};
