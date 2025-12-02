/*
 * global.h
 *
 *  Created on: Oct 31, 2025
 *      Author: Thanh Phong
 */
#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "display.h"

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT			0
#define RED_GREEN_AUTO	1
#define RED_AMBER_AUTO	2
#define GREEN_RED_AUTO	3
#define AMBER_RED_AUTO	4

#define MAN_RED 	12
#define MAN_YELLOW 	13
#define MAN_GREEN 	14
#define CROSS 		15

extern int status;

extern int temp_red;
extern int temp_yellow;
extern int temp_green;
extern int time_red;
extern int time_yellow;
extern int time_green;

extern int counter1;
extern int counter2;
void check();

#endif /* INC_GLOBAL_H_ */
