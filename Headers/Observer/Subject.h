#pragma once

#include "../Observer/Observer.h"
using namespace std;

class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(Observer* o) = 0;
    virtual void detach(Observer* o) = 0;
    virtual void notify() = 0;
};
