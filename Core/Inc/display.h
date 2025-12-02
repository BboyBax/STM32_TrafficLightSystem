/*
 * display.h
 *
 *  Created on: Dec 2, 2025
 *      Author: minhp
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "main.h"
#include "i2c-lcd.h"

void setRed(int road);
void setAmber(int road);
void setGreen(int road);
void turnOffAllLEDs(void);

void updateLEDBuffer(int num1, int num2);
const char* getTrafficLightState(int road);

#endif /* INC_DISPLAY_H_ */
