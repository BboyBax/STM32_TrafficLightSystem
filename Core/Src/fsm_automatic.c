/*
 * fsm_automatic.c
 *
 *  Created on: Oct 11, 2025
 *      Author: minhp
 */

#include "fsm_automatic.h"

void fsm_automatic_run(void) {
    switch (status) {
        case INIT:
            turnOffAllLEDs();
            counter1 = time_red;
            counter2 = time_green;

            updateLEDBuffer(counter1, counter2);

            status = AUTO_RED_GREEN;
            setTimer(0, time_green * 1000);
            setTimer(1, 1000);
            break;

        case AUTO_RED_GREEN:
            setRed(1);
            setGreen(2);

            if (isTimerExpired(1) == 1) {
                counter1--;
                counter2--;
                updateLEDBuffer(counter1, counter2);
                setTimer(1, 1000);
            }

            if (isTimerExpired(0) == 1) {
                status = AUTO_RED_AMBER;
                counter1 = time_red - time_green;
                counter2 = time_amber;
                setTimer(0, time_amber * 1000);
                setTimer(1, 1000);
                updateLEDBuffer(counter1, counter2);
            }
            break;

        case AUTO_RED_AMBER:
            setRed(1);
            setAmber(2);

            if (isTimerExpired(1) == 1) {
                counter1--;
                counter2--;
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

        case AUTO_GREEN_RED:
            setGreen(1);
            setRed(2);

            if (isTimerExpired(1) == 1) {
                counter1--;
                counter2--;
                updateLEDBuffer(counter1, counter2);
                setTimer(1, 1000);
            }

            if (isTimerExpired(0) == 1) {
                status = AUTO_AMBER_RED;
                counter1 = time_amber;
                counter2 = time_red - time_green;
                setTimer(0, time_amber * 1000);
                setTimer(1, 1000);
                updateLEDBuffer(counter1, counter2);
            }
            break;

        case AUTO_AMBER_RED:
            setAmber(1);
            setRed(2);

            if (isTimerExpired(1) == 1) {
                counter1--;
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

        default:
            break;
    }
}
