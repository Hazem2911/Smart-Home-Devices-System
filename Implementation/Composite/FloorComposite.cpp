#include "../../Headers/Composite/FloorComposite.h"
using namespace std;

FloorComposite::FloorComposite(const string& id, const string& name, int floorNumber)
    : DeviceComposite(id, name, "Floor"), floorNumber(floorNumber) {}

int FloorComposite::getFloorNumber() {
    return floorNumber;
}
