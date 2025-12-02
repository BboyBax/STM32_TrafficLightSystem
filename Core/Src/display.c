/*
 * display.c
 *
 *  Created on: Dec 2, 2025
 *      Author: minhp
 */

#include "display.h"
#include "global.h"
#include <stdio.h>

void setRed(int road) {
    if (road == 1) {
        HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
    } else if (road == 2) {
    	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
    }
}

void setAmber(int road) {
    if (road == 1) {
    	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
    } else if (road == 2) {
    	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
    }
}

void setGreen(int road) {
    if (road == 1) {
    	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
    } else if (road == 2) {
    	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
    }
}

int old_num1 = -1;
int old_num2 = -1;
int old_status = -1;

const char* getTrafficLightState(int road) {
    switch (status) {
        case RED_GREEN_AUTO:
            return (road == 1) ? "RED" : "GREEN";
        case RED_AMBER_AUTO:
            return (road == 1) ? "RED" : "AMBER";
        case GREEN_RED_AUTO:
            return (road == 1) ? "GREEN" : "RED";
        case AMBER_RED_AUTO:
            return (road == 1) ? "AMBER" : "RED";

        case MAN_RED:
        case MAN_YELLOW:
        case MAN_GREEN:
            return "RED";
        default:
            return "---";
    }
}

void updateLEDBuffer(int num1, int num2) {
    char str_buff[17];

    const char* state1;
    const char* state2;

    if (num1 != old_num1 || num2 != old_num2 || status != old_status) {

        switch (status) {
            case RED_GREEN_AUTO:
            case RED_AMBER_AUTO:
            case GREEN_RED_AUTO:
            case AMBER_RED_AUTO:
            case INIT:

                state1 = getTrafficLightState(1);
                state2 = getTrafficLightState(2);

                lcd_goto_XY(1, 0);
                sprintf(str_buff, "R1:%02d - %s ", num1, state1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "R2:%02d - %s ", num2, state2);
                lcd_send_string(str_buff);
                break;

            case MAN_RED:
            	lcd_clear_display();
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "MODE: 2 (RED) ");
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "SET R: %02d ", temp_red);
                lcd_send_string(str_buff);
                break;

            case MAN_YELLOW:
            	lcd_clear_display();
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "MODE: 3 (AMBER)");
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "SET A: %02d ", temp_yellow);
                lcd_send_string(str_buff);
                break;

            case MAN_GREEN:
            	lcd_clear_display();
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "MODE: 4 (GREEN)");
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "SET G: %02d ", temp_green);
                lcd_send_string(str_buff);
                break;

            default:
                lcd_clear_display();
                lcd_goto_XY(1, 0);
                lcd_send_string("Mode 1: Traffic");
                break;
        }

        old_num1 = num1;
        old_num2 = num2;
        old_status = status;
    }
}

void turnOffAllLEDs(void) {
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
}

