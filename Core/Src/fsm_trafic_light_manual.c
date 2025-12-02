/*
 * manual.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Thanh Phong
 */

#include "fsm_traffic_light_manual.h"
#include "global.h"
#include "display.h"

int temp_red = 0;
int temp_yellow = 0;
int temp_green = 0;
int time_red = 6;
int time_yellow = 2;
int time_green = 4;

void fsm_manual_run(){
	switch(status){
		case MAN_RED:
			updateLEDBuffer(2, temp_red);
			if(isButtonPressed(0)){
				status=MAN_YELLOW;
				turnOffAllLEDs();
				setTimer(4, 50);
				setButtonFlag(0);
			}
			if(isButtonPressed(1)){
				temp_red++;
				if(temp_red>=99){
					temp_red=0;
				}
				updateLEDBuffer(2, temp_red); // Cập nhật hiển thị ngay
				setButtonFlag(1);
			}
			if(isButtonPressed(2)){
				time_red = temp_red;
				time_green = temp_green;
				time_yellow = temp_yellow;

				turnOffAllLEDs(); // Tắt tất cả đèn trước khi về AUTO
				counter1 = time_red;
				counter2 = time_green;
				setTimer(0, 100);
				setTimer(1, counter2*100);
				updateLEDBuffer(counter1, counter2);
				setButtonFlag(2);
			}
			if(isButtonPressed(3)){
				status=CROSS;
			}
			if(isTimerExpired(4)){
				// Chỉ toggle đèn đỏ
				HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
				HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
				HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
				HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
				setTimer(4, 50);
			}
			break;

		case MAN_YELLOW:
		    updateLEDBuffer(3, temp_yellow);
		    if(isButtonPressed(0)){
		    	status = MAN_GREEN;
		    	check();
		    	turnOffAllLEDs(); // Tắt đèn vàng trước khi chuyển sang xanh
		    	setTimer(4, 50);
		    }
		    if(isButtonPressed(1)){
		    	if(temp_yellow>=99){
		    		temp_yellow=0;
		    	}
		    	temp_yellow++;
		    	updateLEDBuffer(3, temp_yellow); // Cập nhật hiển thị ngay
		    }
		    if(isButtonPressed(2)){
		    	check();
		        time_red = temp_red;
		        time_green = temp_green;
		        time_yellow = temp_yellow;
		        turnOffAllLEDs(); // Tắt tất cả đèn trước khi về AUTO
		        counter1 = time_red;
		        counter2 = time_green;
		        setTimer(0, 100);
		        setTimer(1, counter2*100);
		        updateLEDBuffer(counter1, counter2);
		    }
		    if(isButtonPressed(3)){
				status=CROSS;
			}
		    if(isTimerExpired(4)){
		        // Chỉ toggle đèn vàng
		        HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
		        HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
		        setTimer(4, 50);
		    }
		    break;

		case MAN_GREEN:
		    updateLEDBuffer(4, temp_green);
		    if(isButtonPressed(0)){
		    	status = INIT; // Quay về AUTO mode
		    	turnOffAllLEDs(); // Tắt tất cả đèn
		    }
		    if(isButtonPressed(1)){
		    	if(temp_green>=99){
					temp_green=0;
				}
		    	temp_green++;
		    	updateLEDBuffer(4, temp_green); // Cập nhật hiển thị ngay
		    }
		    if(isButtonPressed(2)){
		    	check();
		        time_red = temp_red;
		        time_green = temp_green;
		        time_yellow = temp_yellow;

		        turnOffAllLEDs(); // Tắt tất cả đèn trước khi về AUTO
		        counter1 = time_red;
		        counter2 = time_green;
		        setTimer(0, 100);
		        setTimer(1, counter2*100);
		        updateLEDBuffer(counter1, counter2);
		    }
		    if(isButtonPressed(3)){
				status=CROSS;
			}
		    if(isTimerExpired(4)){
		        // Chỉ toggle đèn xanh
		    	HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
				HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
		        setTimer(4, 50);
		    }
		    break;
		case CROSS:
			setTimer(5,1500);
			setTimer(6,100);
			time_red=15;
			counter1 = time_red;
			counter2 = time_red;
			if(isTimerExpired(6)){
				counter1 --;
				counter2 --;
				updateLEDBuffer(counter1, counter2);
				setTimer(6,100);
			}
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
			if(isTimerExpired(5)){
				status = INIT;

			}
			break;
	}
}
