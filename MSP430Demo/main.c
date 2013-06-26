#include <msp430.h> 
#include <stdint.h>

/*
 * main.c
 */
#include "LedDriver.h"

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    uint16_t ledLocation;
	LedDriver_Create(&ledLocation);
	return 0;
}
