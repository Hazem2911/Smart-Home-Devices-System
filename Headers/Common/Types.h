#pragma once

enum class DeviceStatus {
    ON,
    OFF,
    ERROR,
    STANDBY
};

enum class LightState {
    ON,
    OFF,
    DIMMED
};

enum class ThermoMode {
    HEATING,
    COOLING,
    AUTO,
    OFF
};
