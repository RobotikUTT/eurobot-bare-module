#include <Wire.h>
#include <SPI.h>
#include "mcp_can.h"
#include "CanBus.h"
#include "TestLib.h"

void setup() {

	Serial.begin(115200);
	CanBus.begin(CAN_5KBPS);

}

void loop() {

}

