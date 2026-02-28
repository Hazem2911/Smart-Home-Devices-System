#include "../../Headers/Client/Client.h"
#include "../../Headers/Factory/BasicFactory.h"
#include "../../Headers/Factory/PremiumFactory.h"
#include "../../Headers/Factory/AbstractSmartLight.h"
#include "../../Headers/Factory/AbstractSmartThermostat.h"
#include "../../Headers/Factory/AbstractSmartCamera.h"
#include "../../Headers/Adapter/LegacyDevice.h"
#include "../../Headers/Adapter/LegacyDeviceAdapter.h"
#include "../../Headers/Composite/FloorComposite.h"
#include "../../Headers/Composite/RoomComposite.h"
#include "../../Headers/Command/TurnLightONComm.h"
#include "../../Headers/Command/TurnLightOFFComm.h"
#include "../../Headers/Strategy/ComfortAutomationMode.h"
#include "../../Headers/Strategy/EnergySavingMode.h"

#include <iostream>
using namespace std;

static void section(const string& title) {
    cout << "\n--- " << title << " ---" << endl;
}

Client::Client() {
    hub = new SmartHomeHub(new PremiumFactory());
    controller = new AutomationController();
}

Client::~Client() {
    delete controller;
    delete hub;
}

void Client::setupSystem() {
    cout << "\n=== Setting Up Smart Home System ===" << endl;

    // --- Abstract Factory ---
    section("Abstract Factory");

    BasicFactory basicF;

    AbstractSmartLight* basicLed = basicF.createLight("LED"); // Basic Led Light
    AbstractSmartLight* basicHal = basicF.createLight("HALOGEN"); // Basic Halogen Light
    AbstractSmartThermostat* basicThermo = basicF.createThermostat("A"); // Basic Thermo A
    AbstractSmartCamera* basicCam = basicF.createCamera("WIRED"); // Basic Wired Camera
    basicLed->turnOn();
    basicLed->adjustbrightness(60);
    cout << "Basic LED type  : " << basicLed->getType() << endl;
    cout << "Basic HAL type  : " << basicHal->getType() << endl;

    PremiumFactory premiumF;
    AbstractSmartLight* premiumLed = premiumF.createLight("LED"); // Premium Led Light
    AbstractSmartLight* premiumHal = premiumF.createLight("HALOGEN"); // Premium Halogen Light
    AbstractSmartThermostat* premiumThermo = premiumF.createThermostat("B"); // Premium Thermo B
    AbstractSmartCamera* premiumCam = premiumF.createCamera("WIRELESS"); // Premium Wireless Camera
    premiumLed->turnOn();
    premiumLed->adjustbrightness(80);
    cout << "premium LED type: " << premiumLed->getType() << endl;
    cout << "premium HAL type: " << premiumHal->getType() << endl;

    delete basicLed; delete basicHal; delete basicThermo; delete basicCam;
    delete premiumLed; delete premiumHal; delete premiumThermo; delete premiumCam;

    // --- Adapter ---
    section("Adapter");

    LegacyDevice* legacy = new LegacyDevice("EXT-001", "OldVendorCam", "RS-232");
    LegacyDeviceAdapter* adapter = new LegacyDeviceAdapter("adp-01", "Legacy Security Cam", legacy);

    adapter->turnOn();
    adapter->control();
    adapter->turnOff();
    cout << "Adapter DeviceStatus: " << (adapter->getStatus() == DeviceStatus::OFF ? "OFF" : "ON") << endl;

    delete adapter;

    // --- Composite ---
    section("Composite");

    SmartDevice* devA = new SmartDevice("d-A", "Living LED", "BrandX");
    SmartDevice* devB = new SmartDevice("d-B", "Living Thermo", "BrandX");
    SmartDevice* devC = new SmartDevice("d-C", "Bedroom HAL", "BrandX");

    RoomComposite*  living  = new RoomComposite ("r-01","LivingRoom","Living");
    RoomComposite*  bedroom = new RoomComposite ("r-02", "Bedroom", "Sleeping");
    FloorComposite* floor1  = new FloorComposite("f-01", "Ground Floor", 1);

    living->add(devA); 
    living->add(devB);

    bedroom->add(devC);

    floor1->add(living); 
    floor1->add(bedroom);

    cout << ">> floor1->turnOn():" << endl;
    floor1->turnOn();
    cout << ">> floor1->turnOff():" << endl;
    floor1->turnOff();

    delete devA; delete devB; delete devC;
    delete living; delete bedroom; delete floor1;

    // --- Observer ---
    section("Observer");
    // De el registered devices fel observer --
    SmartDevice* light1 = hub->addDevice("LED Light", "LivingRoom");
    SmartDevice* light2 = hub->addDevice("HAL Light", "Bedroom");
    SmartDevice* camera1 = hub->addDevice("Camera",    "EntryHall");

    light1->attach(controller);
    camera1->attach(controller);

    cout << ">> light1->turnOn():" << endl;  light1->turnOn();
    cout << ">> light1->turnOff():" << endl; light1->turnOff();
    cout << ">> camera1->turnOn():" << endl; camera1->turnOn();

    cout << ">> detach controller from light1:" << endl;
    light1->detach(controller);
    cout << ">> light1->turnOn() (no controller output expected):" << endl;
    light1->turnOn(); // :)

    light1->attach(controller);

    // --- State ---
    section("State");

    cout << "light2 starts in: " << light2->getCurrentState()->getStateName() << endl;

    cout << ">> turnOn() while OFF:" << endl;
    light2->turnOn();
    cout << "State: " << light2->getCurrentState()->getStateName() << endl;

    cout << ">> turnOn() while ON (guard):" << endl;
    light2->turnOn();
    cout << "State: " << light2->getCurrentState()->getStateName() << endl;

    cout << ">> dim(40) while ON:" << endl;
    light2->dim(40);
    cout << "State: " << light2->getCurrentState()->getStateName() << endl;

    cout << ">> dim(20) while DIMMED:" << endl;
    light2->dim(20);
    cout << "State: " << light2->getCurrentState()->getStateName() << endl;

    cout << ">> turnOff() while DIMMED:" << endl;
    light2->turnOff();
    cout << "State: " << light2->getCurrentState()->getStateName() << endl;

    cout << ">> dim(50) while OFF (guard):" << endl;
    light2->dim(50);
    cout << "State: " << light2->getCurrentState()->getStateName() << endl;

    // ---Command + Undo ---
    section("Command + Undo");

    light1->turnOff();

    TurnLightONComm*  cmdOn  = new TurnLightONComm(light1);
    TurnLightOFFComm* cmdOff = new TurnLightOFFComm(light2);

    cout << ">> Execute TurnLightONComm:" << endl;
    hub->executeAutomation(cmdOn);
    cout << "State: " << light1->getCurrentState()->getStateName() << endl;
    cout << ">> Undo TurnLightONComm:" << endl;
    cmdOn->undo();
    cout << "State: " << light1->getCurrentState()->getStateName() << endl;

    light2->turnOn();
    cout << ">> Execute TurnLightOFFComm:" << endl;
    hub->executeAutomation(cmdOff);
    cout << "State: " << light2->getCurrentState()->getStateName() << endl;
    cout << ">> Undo TurnLightOFFComm:" << endl;
    cmdOff->undo();
    cout << "State: " << light2->getCurrentState()->getStateName() << endl;

    delete cmdOn;
    delete cmdOff;

    cout << "\n=== System Setup Complete ===" << endl;
}

void Client::run() {
    cout << "\n=== Running Smart Home System ===" << endl;

    // --- Strategy ---
    section("Strategy");

    cout << ">> ComfortAutomationMode(temp=22, brightness=80):" << endl;
    hub->setMode(new ComfortAutomationMode(22, 80));
    cout << "Devices in LivingRoom: " << hub->getDevicesByZone("LivingRoom").size() << endl;

    cout << ">> EnergySavingMode(maxDevices=1, shutdownDelay=30s):" << endl;
    hub->setMode(new EnergySavingMode(1, 30));

}