/*
 * global.c
 *
 *  Created on: Oct 11, 2025
 *      Author: minhp
 */

#include "global.h"

int status = INIT;
int counter1 = 0;
int counter2 = 0;

int time_red = 7;
int time_amber = 2;
int time_green = 5;

int temp_red = 0;
int temp_amber = 0;
int temp_green = 0;

void checkTrafficTime(void) {
	if (time_red < 1) time_red = 1;
	if (time_amber < 1) time_amber = 1;
	if (time_green < 1) time_green = 1;

	if (time_red == time_amber + time_green) {
		return;
	}

	time_amber = time_red - time_green;
	if (time_amber < 1) {
		time_amber = 1;
		time_green = time_red - time_amber;
		if (time_green < 1) {
			time_green = 1;
			time_red = time_green + time_amber;
		}
	}
}
