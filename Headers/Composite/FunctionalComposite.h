#pragma once
#include <string>
#include "DeviceComposite.h"

using namespace std;

class FunctionalComposite : public DeviceComposite {
private:
    string functionType;

public:
    FunctionalComposite(const string& id, const string& name, const string& functionType);

    string getFunctionType();
};
