#include "../../Headers/Composite/RoomComposite.h"
using namespace std;

RoomComposite::RoomComposite(const string& id, const string& name, const string& roomType)
    : DeviceComposite(id, name, "Room"), roomType(roomType) {}

string RoomComposite::getRoomType() {
    return roomType;
}
