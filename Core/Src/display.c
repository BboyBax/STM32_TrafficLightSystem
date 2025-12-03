/*
 * display.c
 *
 *  Created on: Dec 2, 2025
 *      Author: minhp
 */

#include "display.h"
#include "global.h"
#include <stdio.h>
#include <string.h>

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

void turnOffAllLEDs(void) {
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
}

int old_num1 = -1;
int old_num2 = -1;
int old_status = -1;

void updateLEDBuffer(int num1, int num2) {
    char str_buff[17];

    if (num1 != old_num1 || num2 != old_num2 || status != old_status) {

        switch (status) {
            case AUTO_RED_GREEN:
            case AUTO_RED_AMBER:
            case AUTO_GREEN_RED:
            case AUTO_AMBER_RED:
            case INIT:
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "Road 1:%02d ", num1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "Road 2:%02d", num2);
                lcd_send_string(str_buff);
                break;

            case MAN_RED:
            	memset(str_buff, 0, sizeof(str_buff));
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "MODE: %02d ", num1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "SET R: %02d ", num2);
                lcd_send_string(str_buff);
                break;

            case MAN_AMBER:
            	memset(str_buff, 0, sizeof(str_buff));
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "MODE: %02d ", num1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "SET A: %02d ", num2);
                lcd_send_string(str_buff);
                break;

            case MAN_GREEN:
            	memset(str_buff, 0, sizeof(str_buff));
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "MODE: %02d ", num1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "SET G: %02d ", num2);
                lcd_send_string(str_buff);
                break;
            case PEDESTRIAN_RED_AMBER:
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "Road 1:%02d ", num1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "Road 2:%02d", num2);
                lcd_send_string(str_buff);
                break;
            case PEDESTRIAN_RED_GREEN:
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "Road 1:%02d ", num1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "Road 2:%02d", num2);
                lcd_send_string(str_buff);
                break;

            case PEDESTRIAN_RED_RED1:
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "Road 1:%02d ", num1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "Road 2:%02d", num2);
                lcd_send_string(str_buff);
                break;
            case PEDESTRIAN_AMBER_RED:
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "Road 1:%02d ", num1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "Road 2:%02d", num2);
                lcd_send_string(str_buff);
                break;
            case PEDESTRIAN_GREEN_RED:
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "Road 1:%02d ", num1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "Road 2:%02d", num2);
                lcd_send_string(str_buff);
                break;

            case PEDESTRIAN_RED_RED2:
                lcd_goto_XY(1, 0);
                sprintf(str_buff, "Road 1:%02d ", num1);
                lcd_send_string(str_buff);

                lcd_goto_XY(2, 0);
                sprintf(str_buff, "Road 2:%02d", num2);
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
