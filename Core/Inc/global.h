/*
 * global.h
 *
 *  Created on: Oct 11, 2025
 *      Author: minhp
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "led_display.h"

#define INIT			0
#define AUTO_RED_GREEN	1
#define AUTO_RED_AMBER	2
#define AUTO_GREEN_RED	3
#define AUTO_AMBER_RED	4

#define MAN_RED			12
#define MAN_AMBER		13
#define MAN_GREEN		14

extern int status;
extern int counter1;
extern int counter2;

extern int time_red;
extern int time_amber;
extern int time_green;

extern int temp_red;
extern int temp_amber;
extern int temp_green;

void checkTrafficTime(void);

#endif /* INC_GLOBAL_H_ */
