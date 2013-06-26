/*
 * ledDriverTest.c
 *
 *  Created on: Jun 25, 2013
 *      Author: Julian Brown
 */


extern "C" {

#include "LedDriver.h"

}

#include <CppUTest/TestHarness.h>

static uint16_t virtualLeds;

TEST_GROUP(LedDriver){

	void setup() {
		virtualLeds = 0xffff;
		LedDriver_Create(&virtualLeds);
	};

	void teardown() {
		LedDriver_Destroy();
	};
};

TEST(LedDriver, Create) {
	virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	CHECK_EQUAL(0, virtualLeds);
}

TEST(LedDriver, TurnOnLEDOne) {
	setup();
	LedDriver_TurnOn(1);
	CHECK_EQUAL(1, virtualLeds);
}

TEST(LedDriver, TurnOnAnyLED) {
	setup();
	LedDriver_TurnOn(2);
	LedDriver_TurnOn(5);
	CHECK_EQUAL(0x12, virtualLeds);
}

TEST(LedDriver, TurnOnAllLEDs) {
	setup();
	LedDriver_TurnOnAll();
	CHECK_EQUAL(0xFFFF, virtualLeds);
}

TEST(LedDriver, TurnOffAnLED) {
	setup();
	LedDriver_TurnOnAll();
	LedDriver_TurnOff(1);
	LedDriver_TurnOff(3);
	CHECK_EQUAL(0xFFFA, virtualLeds);
}

TEST(LedDriver, TurnOffAllLEDs) {
	setup();
	LedDriver_TurnOnAll();
	LedDriver_TurnOffAll();
	CHECK_EQUAL(0, virtualLeds);
}
