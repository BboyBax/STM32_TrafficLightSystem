/*
 * pedestrian_crossing.c
 *
 *  Created on: Dec 3, 2025
 *      Author: Ha Trong Son
 */

#include "pedestrian_crossing.h"

void pedestrian_cossing(){
	int red_pedestrian = 15;
	int green_pedestrian = 10;
	int amber_pedestrian = 2;
	switch (status){

	case PEDESTRIAN_RED_GREEN:
		setRed(1);
		setGreen(2);
		counter1 = red_pedestrian;
		if (counter2 > 10){
			counter2 = green_pedestrian;
		}
        if (isTimerExpired(1) == 1) {
            counter2--;
            updateLEDBuffer(counter1, counter2);
            setTimer(1, 1000);
        }
        if (isTimerExpired(0) == 1) {
        	status = PEDESTRIAN_RED_AMBER;
            counter2 = amber_pedestrian;
            setTimer(0, amber_pedestrian * 1000);
            setTimer(1, 1000);
            updateLEDBuffer(counter1, counter2);
        }
        break;
	case PEDESTRIAN_RED_AMBER:
		setRed(1);
		setAmber(2);
		if (counter2 > amber_pedestrian){
			counter2 = amber_pedestrian;
		}
        if (isTimerExpired(1) == 1) {
            counter2--;
            updateLEDBuffer(counter1, counter2);
            setTimer(1, 1000);
        }
        if (isTimerExpired(0) == 1) {
        	status = PEDESTRIAN_RED_RED1;
            counter2 = red_pedestrian;
            counter1 = red_pedestrian;
            setTimer(0, red_pedestrian * 1000);
            setTimer(1, 1000);
            updateLEDBuffer(counter1, counter2);
        }
        break;
	case PEDESTRIAN_RED_RED1:
		setRed(1);
		setRed(2);
        if (isTimerExpired(1) == 1) {
        	counter1--;
            updateLEDBuffer(counter1, counter2);
            setTimer(1, 1000);
        }
        if (isTimerExpired(0) == 1) {
            status = AUTO_GREEN_RED;
            counter1 = time_green;
            counter2 = time_red;
            setTimer(0, time_green * 1000);
            setTimer(1, 1000);
            updateLEDBuffer(counter1, counter2);
        }
        break;


	case PEDESTRIAN_GREEN_RED:
		setGreen(1);
		setRed(2);
		counter2 = red_pedestrian;
		if (counter1 > green_pedestrian){
			counter1 = green_pedestrian;
		}
        if (isTimerExpired(1) == 1) {
            counter1--;
            updateLEDBuffer(counter1, counter2);
            setTimer(1, 1000);
        }
        if (isTimerExpired(0) == 1) {
        	status = PEDESTRIAN_AMBER_RED;
            counter1 = amber_pedestrian;
            setTimer(0, amber_pedestrian * 1000);
            setTimer(1, 1000);
            updateLEDBuffer(counter1, counter2);
        }
        break;
	case PEDESTRIAN_AMBER_RED:
		setAmber(1);
		setRed(2);
		if (counter1 > amber_pedestrian){
			counter1 = amber_pedestrian;
		}
        if (isTimerExpired(1) == 1) {
            counter1--;
            updateLEDBuffer(counter1, counter2);
            setTimer(1, 1000);
        }
        if (isTimerExpired(0) == 1) {
        	status = PEDESTRIAN_RED_RED2;
            counter2 = red_pedestrian;
            counter1 = red_pedestrian;
            setTimer(0, red_pedestrian * 1000);
            setTimer(1, 1000);
            updateLEDBuffer(counter1, counter2);
        }
        break;
	case PEDESTRIAN_RED_RED2:
		setRed(1);
		setRed(2);
        if (isTimerExpired(1) == 1) {
        	counter2--;
            updateLEDBuffer(counter1, counter2);
            setTimer(1, 1000);
        }
        if (isTimerExpired(0) == 1) {
            status = AUTO_RED_GREEN;
            counter1 = time_red;
            counter2 = time_green;
            setTimer(0, time_green * 1000);
            setTimer(1, 1000);
            updateLEDBuffer(counter1, counter2);
        }
        break;
	}
}
