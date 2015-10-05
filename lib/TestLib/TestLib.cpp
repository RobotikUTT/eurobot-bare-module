#include <Arduino.h>
#include "TestLib.h"

TestClass::TestClass() {
	Serial.begin(9600);
}

void TestClass::firstMethod() {
	Serial.println("FirstMethod");
}

void TestClass::secondMethod() {
	Serial.println("SecondMethod");
}
