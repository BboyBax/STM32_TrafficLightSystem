/*
 * fsm_mode.c
 *
 *  Created on: Nov 11, 2025
 *      Author: minhp
 */

#include "fsm_mode.h"


void fsm_mode_run(void) {
    if (isButtonPressed(0) == 1) {
        if (status == INIT || (status >= AUTO_RED_GREEN && status <= AUTO_AMBER_RED)) {
            status = MAN_RED;
            turnOffAllLEDs();
            temp_red = 1;
            temp_amber = 1;
            temp_green = 1;
            setTimer(2, 500);
            updateLEDBuffer(2, temp_red);
        }
        else if (status == MAN_RED) {
            status = MAN_AMBER;
            turnOffAllLEDs();
            updateLEDBuffer(3, temp_amber);
        }
        else if (status == MAN_AMBER) {
            status = MAN_GREEN;
            turnOffAllLEDs();
            updateLEDBuffer(4, temp_green);
        }
        else if (status == MAN_GREEN) {
            checkTrafficTime();
            temp_red = 1;
            temp_amber = 1;
            temp_green = 1;
            status = INIT;
            turnOffAllLEDs();
        }
    }
}
