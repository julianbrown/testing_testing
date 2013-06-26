/*
 * testmain.c
 *
 *  Created on: Jun 25, 2013
 *      Author: Julian Brown
 */

#include "LedDriver.h"
#include "minunit.h"

int tests_run = 0;
static uint16_t virtual_leds = 0xffff;

void setup () {
	LedDriver_Create(&virtual_leds);
}

static char * test_create () {
	LedDriver_Create(&virtual_leds);
	mu_assert("LED driver not initialized correctly!", virtual_leds == 0);
	return 0;
}

static char * test_turn_on_led_one() {
	setup();
	LedDriver_TurnOn(1);
	mu_assert("Correct led not turned on!", virtual_leds == 1);
	return 0;
}

static char * test_turn_on_multiple_leds() {
	setup();
	LedDriver_TurnOn(2);
	LedDriver_TurnOn(4);
	LedDriver_TurnOn(8);
	mu_assert("Correct LEDs not turned on", virtual_leds == 0x8A);
	return 0;
}

static char * test_turn_on_all_leds() {
	setup();
	LedDriver_TurnOnAll();
	mu_assert("All LEDs not turned on", virtual_leds == 0xff);
	return 0;
}

static char * test_turn_off_an_led () {
	setup();
	LedDriver_TurnOnAll();
	LedDriver_TurnOff(8);
	mu_assert("Proper LED not turned off", virtual_leds == 0x7f);
	return 0;
}

static char * test_turn_off_all_leds () {
	setup();
	LedDriver_TurnOnAll();
	LedDriver_TurnOffAll();
	mu_assert("All LEDs not turned off", virtual_leds == 0);
	return 0;
}

static char * all_tests() {
	mu_run_test(test_create);
	mu_run_test(test_turn_on_led_one);
	mu_run_test(test_turn_on_multiple_leds);
	mu_run_test(test_turn_on_all_leds);
	mu_run_test(test_turn_off_an_led);
	mu_run_test(test_turn_off_all_leds);
	return 0;
}

int main(int argc, char** argv){
	char* result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED!\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
