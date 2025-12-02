/*
 * manual.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Thanh Phong
 */

#include "fsm_traffic_light_manual.h"
#include "global.h"

void fsm_manual_run(){
	switch(status){
		case MAN_RED:
			updateLEDBuffer(2, temp_red);

			if(isButtonPressed(0)){
				status=MAN_YELLOW;
				turnOffAllLEDs();
				setTimer(4, 500);
				setButtonFlag(0);
			}
			if(isButtonPressed(1)){
				temp_red++;
				updateLEDBuffer(2, temp_red); // Cập nhật hiển thị ngay
				setButtonFlag(1);
			}
			if(isButtonPressed(2)){
				check();
				time_red = temp_red;
				time_green = temp_green;
				time_yellow = temp_yellow;
				status = INIT;
				turnOffAllLEDs(); // Tắt tất cả đèn trước khi về AUTO
				counter0 = time_red;
				counter1 = time_green;
				setTimer(0, 1000);
				setTimer(1, counter1*1000);
				updateLEDBuffer(counter0, counter1);
				setButtonFlag(2);
			}
			if(isTimerExpired(4)){
				// Chỉ toggle đèn đỏ
				HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
				HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
				HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
				HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
				setTimer(4, 500);
			}
			break;

		case MAN_YELLOW:
		    updateLEDBuffer(3, temp_yellow);

		    if(isbuttonpressed(0)){
		    	status = MAN_GREEN;
		    	turnOffAllLEDs(); // Tắt đèn vàng trước khi chuyển sang xanh
		    	setTimer(4, 500);
		    }
		    if(isbuttonpressed(1)){
		    	temp_yellow++;
		    	updateLEDBuffer(3, temp_yellow); // Cập nhật hiển thị ngay
		    }
		    if(isbuttonpressed(2)){
		    	check();
		        time_red = temp_red;
		        time_green = temp_green;
		        time_yellow = temp_yellow;
		        status = INIT;
		        turnOffAllLEDs(); // Tắt tất cả đèn trước khi về AUTO
		        counter0 = time_red;
		        counter1 = time_green;
		        setTimer(0, 1000);
		        setTimer(1, counter1*1000);
		        updateLEDBuffer(counter0, counter1);
		    }
		    if(isTimerExpired(4)){
		        // Chỉ toggle đèn vàng
		        HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
		        setTimer(4, 500);
		    }
		    break;

		case MAN_GREEN:
		    updateLEDBuffer(4, temp_green);

		    if(isbuttonpressed(0)){
		    	status = INIT; // Quay về AUTO mode
		    	turnOffAllLEDs(); // Tắt tất cả đèn
		    }
		    if(isbuttonpressed(1)){
		    	temp_green++;
		    	updateLEDBuffer(4, temp_green); // Cập nhật hiển thị ngay
		    }
		    if(isbuttonpressed(2)){
		    	check();
		        time_red = temp_red;
		        time_green = temp_green;
		        time_yellow = temp_yellow;
		        status = INIT;
		        turnOffAllLEDs(); // Tắt tất cả đèn trước khi về AUTO
		        counter0 = time_red;
		        counter1 = time_green;
		        setTimer(0, 1000);
		        setTimer(1, counter1*1000);
		        updateLEDBuffer(counter0, counter1);
		    }
		    if(isTimerExpired(4)){
		        // Chỉ toggle đèn xanh
		        HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
		        setTimer(4, 500);
		    }
		    break;
	}
}
