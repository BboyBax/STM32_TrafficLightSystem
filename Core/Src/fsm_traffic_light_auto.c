/*
 * fsm_traffic_light_auto.c
 *
 *  Created on: Dec 2, 2025
 *      Author: Ha Trong Son
 */


#include "fsm_traffic_light_auto.h"
#include "global.h"

int red_counter = 7;
int amber_counter = 2;
int green_counter = 5;


void fsm_traffic_light_auto(){
	switch (status) {
	case INIT:
		lcd_clear_display();
		turnOffAllLEDs();
        counter1 = red_counter;
        counter2 = green_counter;

        updateLEDBuffer(counter1, counter2);

        setTimer(19, green_counter * 100);
        setTimer(18, 100);
        setTimer(17, 1);
        status = RED_GREEN_AUTO;

		break;
	case RED_GREEN_AUTO:
//		if (isButtonPressed(0) == 1){
//
//		}
        setRed(1);
        setGreen(2);
        if (isTimerExpired(18) == 1){
			counter1--;
			counter2--;
			updateLEDBuffer(counter1, counter2);
			setTimer(18, 100);
        }
        if (isTimerExpired(19) == 1){
			status = RED_AMBER_AUTO;
			counter1 = amber_counter;
			counter2 = amber_counter;
			setTimer(19, amber_counter * 100);
        }
		break;
	case RED_AMBER_AUTO:
//		if (isButtonPressed(0) == 1){
//
//		}
		setRed(1);
		setAmber(2);
        if (isTimerExpired(18) == 1){
			counter1--;
			counter2--;
			updateLEDBuffer(counter1, counter2);
			setTimer(18, 100);
        }
        if (isTimerExpired(19) == 1){
			status = GREEN_RED_AUTO;
			counter1 = green_counter;
			counter2 = red_counter;
			setTimer(19, green_counter * 100);
        }
		break;
	case GREEN_RED_AUTO:
		//		if (isButtonPressed(0) == 1){
		//
		//		}
		setGreen(1);
		setRed(2);
        if (isTimerExpired(18) == 1){
			counter1--;
			counter2--;
			updateLEDBuffer(counter1, counter2);
			setTimer(18, 100);
        }
        if (isTimerExpired(19) == 1){
			status = AMBER_RED_AUTO;
			counter1 = amber_counter;
			counter2 = amber_counter;
			setTimer(19, amber_counter * 100);
        }
		break;
	case AMBER_RED_AUTO:
		//		if (isButtonPressed(0) == 1){
		//
		//		}
		setAmber(1);
		setRed(2);
        if (isTimerExpired(18) == 1){
			counter1--;
			counter2--;
			updateLEDBuffer(counter1, counter2);
			setTimer(18, 100);
        }
        if (isTimerExpired(19) == 1){
			status = RED_GREEN_AUTO;
			counter1 = red_counter;
			counter2 = green_counter;
			setTimer(19, green_counter * 100);
        }
		break;
	case ERROR:
		break;
	default:
		break;
	}
}
