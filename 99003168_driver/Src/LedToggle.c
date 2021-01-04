/*
 * LedToggle.c
 *
 *  Created on: 01-Oct-2020
 *      Author: Training
 */
#include "STM32F407xx.h"
#include <stdint.h>

void delay(void)
{
	for(uint32_t i=0; i<50000;i++);
}

int main(void)
{
	GPIO_HANDLE_t GPIOLed;
	GPIOLed.pGPIOx = GPIOD;
	GPIOLed.GPIO_PINCONFIG.GPIO_PINNUMBER = GPIO_PINNUMBER_12;
	GPIOLed.GPIO_PINCONFIG.GPIO_PINMODE = GPIO_MODE_OUT;
	GPIOLed.GPIO_PINCONFIG.GPIO_PINSPEED = GPIO_SPEED_VERY_HIGH;
	GPIOLed.GPIO_PINCONFIG.GPIO_PINOPTYPE = GPIO_OP_TYPE_PP;
	GPIOLed.GPIO_PINCONFIG.GPIO_PINPUPDCONTROL = GPIO_NO_PU_PD;
	GPIO_PERICLKCTRL(GPIOD, ENABLE);

	GPIO_INIT(&GPIOLed);
	while(1)
	{
		GPIO_TOGGLEOUTPUTPIN(GPIOD, GPIO_PINNUMBER_12);
		delay();
	}

	return 0;
}

