#include <Arduino.h>
#include <Wire.h>
#include "FooLib.h"
#include "BarLib.h"

BarClass BarObject;

void setup() {
	Serial.begin(115200);
	delay(1000);
}

void loop() {
	BarObject.firstBarMethod();
	delay(1000);
	BarObject.secondBarMethod();
	delay(1000);
}

