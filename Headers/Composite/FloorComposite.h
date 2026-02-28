#pragma once
#include "DeviceComposite.h"

using namespace std;

class FloorComposite : public DeviceComposite {
private:
    int floorNumber;

public:
    FloorComposite(const string& id, const string& name, int floorNumber);

    int getFloorNumber();
};
