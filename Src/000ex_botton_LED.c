/*
 * 002led_button.c
 *
 *  Created on: Feb 1, 2019
 *      Author: admin
 */


#include "stm32f407xx.h"

#define HIGH 1
#define LOW 0
#define BTN_PRESSED LOW

void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}


int main(void)
{

	GPIO_Handle_t GpioLed, GPIOBtn ,GPIOPU;

	//this is led gpio configuration
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed);


	//this is btn gpio configuration
	GPIOBtn.pGPIOx = GPIOB;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOB,ENABLE);

	GPIO_Init(&GPIOBtn);

	GPIOPU.pGPIOx = GPIOD;
	GPIOPU.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_10;
	GPIOPU.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIOPU.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOPU.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOPU.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GPIO_Init(&GPIOPU);
	GPIO_TRUE_OutputPin(GPIOD,GPIO_PIN_NO_10);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOB,GPIO_PIN_NO_12) == BTN_PRESSED)
		{
			delay();
			GPIO_TRUE_OutputPin(GPIOD,GPIO_PIN_NO_12);
		}
		else
		{
			delay();
			GPIO_FALSE_OutputPin(GPIOD,GPIO_PIN_NO_12);
		}
	}
	return 0;
}
