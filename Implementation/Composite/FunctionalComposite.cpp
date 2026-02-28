#include "../../Headers/Composite/FunctionalComposite.h"
using namespace std;

FunctionalComposite::FunctionalComposite(const string& id, const string& name, const string& functionType)
    : DeviceComposite(id, name, "Functional"), functionType(functionType) {}

string FunctionalComposite::getFunctionType() {
    return functionType;
}
