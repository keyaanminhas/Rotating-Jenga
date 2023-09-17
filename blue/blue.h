#pragma once

#include "Arduino.h"

#ifdef ESP32

#include "BluetoothSerial.h"


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif
#endif

class Ble32{
private:

	BluetoothSerial _SerialBT;
	String _name;
public:
	void setup(const String name);
	String read(); // String data type defined in arduino.h
};