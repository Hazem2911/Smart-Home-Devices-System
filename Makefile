# ============================================================
#  Smart Home Devices System — Makefile
#  Compiler : g++ (MSYS2 / MinGW-w64)
#  Standard : C++17
# ============================================================

CXX      := C:/msys64/mingw64/bin/g++.exe
BASH     := C:/msys64/usr/bin/bash.exe
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -I. -static-libgcc -static-libstdc++
TARGET   := SmartHome.exe
BUILD    := build


SRCS :=	Implementation/main.cpp \
		Implementation/Adapter/LegacyDevice.cpp \
		Implementation/Adapter/LegacyDeviceAdapter.cpp \
		Implementation/Client/Client.cpp \
		Implementation/Command/TurnLightOFFComm.cpp \
		Implementation/Command/TurnLightONComm.cpp \
		Implementation/Composite/DeviceComposite.cpp \
		Implementation/Composite/FloorComposite.cpp \
		Implementation/Composite/FunctionalComposite.cpp \
		Implementation/Composite/RoomComposite.cpp \
		Implementation/Composite/SmartDevice.cpp \
		Implementation/Factory/BasicFactory.cpp \
		Implementation/Factory/BasicHalLight.cpp \
		Implementation/Factory/BasicLedLight.cpp \
		Implementation/Factory/BasicSmartThermoA.cpp \
		Implementation/Factory/BasicSmartThermoB.cpp \
		Implementation/Factory/BasicWiredCamera.cpp \
		Implementation/Factory/BasicWirelessCamera.cpp \
		Implementation/Factory/PremiumFactory.cpp \
		Implementation/Factory/PremiumHalogenLight.cpp \
		Implementation/Factory/PremiumLedLight.cpp \
		Implementation/Factory/PremiumSmartThermoA.cpp \
		Implementation/Factory/PremiumSmartThermoB.cpp \
		Implementation/Factory/PremiumWiredCamera.cpp \
		Implementation/Factory/PremiumWirelessCamera.cpp \
		Implementation/Hub/SmartHomeHub.cpp \
		Implementation/Observer/AutomationController.cpp \
		Implementation/State/LightDimmedState.cpp \
		Implementation/State/LightOffState.cpp \
		Implementation/State/LightOnState.cpp \
		Implementation/Strategy/ComfortAutomationMode.cpp \
		Implementation/Strategy/EnergySavingMode.cpp


OBJS     := $(patsubst Implementation/%.cpp, $(BUILD)/%.o, $(SRCS))
OBJ_DIRS := $(sort $(dir $(OBJS)))

.PHONY: all run clean rebuild help

all: $(TARGET)
	@echo ""
	@echo "  Build successful ->  $(TARGET)"
	@echo ""

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# ── Compile each .cpp ────
$(BUILD)/%.o: Implementation/%.cpp
	@$(BASH) -c "mkdir -p $(dir $@)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ── Run the executable ──
run: all
	$(BASH) -c "./$(TARGET)"

# ── Clean build artefacts ─
clean:
	$(BASH) -c "rm -rf $(BUILD) $(TARGET)"
	@echo "  Cleaned."

# ── Full rebuild from scratch ─────
rebuild: clean all


