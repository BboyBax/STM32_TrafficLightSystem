/*
 * display.c
 *
 *  Created on: Dec 2, 2025
 *      Author: minhp
 */

#include "display.h"
//#include "global.h"
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

void updateLEDBuffer(int num1, int num2) {
    char str_buff[16];

    if (num1 != old_num1 || num2 != old_num2) {

        lcd_goto_XY(0, 0);
        sprintf(str_buff, "Road 1: %02d", num1);
        lcd_send_string(str_buff);

        lcd_goto_XY(1, 0);
        sprintf(str_buff, "Road 2: %02d", num2);
        lcd_send_string(str_buff);

        old_num1 = num1;
        old_num2 = num2;
    }
}
