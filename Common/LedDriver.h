/*
 * LedDriver.h
 *
 *  Created on: Jun 25, 2013
 *      Author: Julian Brown
 */

#include <stdio.h>
#include <stdint.h>

#ifndef LEDDRIVER_H_
#define LEDDRIVER_H_

void LedDriver_Create(uint16_t* address);
void LedDriver_Destroy(void);

void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnOffAll();
void LedDriver_TurnOnAll();

#endif /* LEDDRIVER_H_ */
