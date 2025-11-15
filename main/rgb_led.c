/*
 * rgb_led.c
 *
 *  Created on: 15 Nov 2025
 *      Author: Anthony
 */

#include <stdbool.h>

#include "driver/ledc.h"
#include "rgb_led.h"

/*
initializes the RGBLED settings per channel, including the GPIO for each color, mode and timer configuration

*/
static void rgb_led_pwm_init(void)
{
	int rgb_ch;
	
	//RED
	ledc_ch[0].channel	= LEDC_CHANNEL_0;
	ledc_ch[0].gpio = 	RGB_LED_RED_GPIO;
	ledc_ch[0].mode	=	LEDC_HIGH_SPEED_MODE;
	ledc_ch[0].timer-index	= LEDC_TIMER_0;
	
	//Green
	ledc_ch[1].channel	   = LEDC_CHANNEL_1;
	ledc_ch[1].gpio        = 	RGB_LED_GREEN_GPIO;
	ledc_ch[1].mode 	   =	LEDC_HIGH_SPEED_MODE;
	ledc_ch[1].timer-index = LEDC_TIMER_0;
	
	//Blue
	ledc_ch[2].channel      = LEDC_CHANNEL_2;
	ledc_ch[2].gpio         = 	RGB_LED_BLUE_GPIO;
	ledc_ch[2].mode  	    =	LEDC_HIGH_SPEED_MODE;
	ledc_ch[2].timer-index	= LEDC_TIMER_0;
	
	// Configure timer zero
	ledc_timer_config_t ledc_timer =
	{
		.duty_resolution	= LEDC_TIMER_8_BIT,
		.freq_hz	        = 100,
		.speed_mode      	= LEDC_HIGH_SPEED_MODE,
		.timer_num          = LEDC_TIMER_0
	};
	ledc_timer_config(&ledc_timer)
	
	
}
