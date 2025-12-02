/*
 * fsm_traffic_light_auto.h
 *
 *  Created on: Dec 2, 2025
 *      Author: Ha Trong Son
 */

#ifndef INC_FSM_TRAFFIC_LIGHT_AUTO_H_
#define INC_FSM_TRAFFIC_LIGHT_AUTO_H_

#include "main.h"
#include "button.h"
#include "i2c-lcd.h"
#include "software_timer.h"

#define INIT 			0
#define RED_GREEN_AUTO 	1
#define RED_AMBER_AUTO 	2
#define GREEN_RED_AUTO 	3
#define AMBER_RED_AUTO 	4
#define ERROR 			5

void fsm_traffic_light_auto();

#endif /* INC_FSM_TRAFFIC_LIGHT_AUTO_H_ */
