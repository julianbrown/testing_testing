/*
 * LedDriver.c
 *
 *  Created on: Jun 25, 2013
 *      Author: Julian Brown
 */

#include "LedDriver.h"

static uint16_t* ledsAddress;

int numberToBit(int number) {
	return 1 << (number - 1);
}

void LedDriver_Create(uint16_t* address) {
	ledsAddress = address;
	*ledsAddress = 0;
}

void LedDriver_Destroy(void) {

}

void LedDriver_TurnOn(int ledNumber) {
	*ledsAddress |= numberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber) {
	*ledsAddress &= ~numberToBit(ledNumber);
}

void LedDriver_TurnOnAll() {
	*ledsAddress = 0xff;
}

void LedDriver_TurnOffAll() {
	*ledsAddress = 0;
}
