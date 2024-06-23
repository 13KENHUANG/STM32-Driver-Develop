/*
 * 001led_toggle.c
 *
 *  Created on: Apr 21, 2024
 *      Author: user
 */
#include "stm32f407xx.h"

#define HIGH 1
#define BTN_PRESSED HIGH
GPIO_Handle_t GpioLed;
GPIO_Handle_t GpioLed1;
GPIO_Handle_t GpioLed2;
GPIO_Handle_t GpioLed3;
GPIO_Handle_t GPIOBtn;

void delay(void)
{
	for(uint32_t i=0 ; i<500000;i++)
	{

	}
}

void SetLED()
{
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GpioLed);

	GpioLed1.pGPIOx = GPIOD;
	GpioLed1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GpioLed1);

	GpioLed2.pGPIOx = GPIOD;
	GpioLed2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GpioLed2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GpioLed2);

	GpioLed3.pGPIOx = GPIOD;
	GpioLed3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GpioLed3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed3.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GpioLed3);

}

int main(void)
{


	GPIO_PeriClockControl(GPIOD,ENABLE);

	SetLED();

	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA,ENABLE);

	GPIO_Init(&GPIOBtn);
	int count = 0;
	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0) == BTN_PRESSED)
		{
			count ++;
			delay();
			if(count % 4 ==0)
			{
				delay();
				GPIO_TRUE_OutputPin(GPIOD,GPIO_PIN_NO_12);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_13);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_14);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_15);
			}
			else if(count % 4 == 1)
			{
				delay();
				GPIO_TRUE_OutputPin(GPIOD,GPIO_PIN_NO_13);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_12);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_14);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_15);
			}
			else if(count % 4 == 2)
			{
				delay();
				GPIO_TRUE_OutputPin(GPIOD,GPIO_PIN_NO_14);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_13);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_12);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_15);
			}
			else if(count % 4 == 3)
			{
				delay();
				GPIO_TRUE_OutputPin(GPIOD,GPIO_PIN_NO_15);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_13);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_14);
				GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_12);
			}
		}
		/*GPIO_TRUE_OutputPin(GPIOD,GPIO_PIN_NO_12);
		delay();
		GPIO_FALSE_OutputPin(GPIOD,GPIO_PIN_NO_12);
		delay();
		GPIO_TRUE_OutputPin(GPIOD,GPIO_PIN_NO_13);
		delay();
		GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_13);
		delay();
		GPIO_TRUE_OutputPin(GPIOD,GPIO_PIN_NO_14);
		delay();
		GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_14);
		delay();
		GPIO_TRUE_OutputPin(GPIOD, GPIO_PIN_NO_15);
		delay();
		GPIO_FALSE_OutputPin(GPIOD, GPIO_PIN_NO_15);
		delay();*/
	}
	return 0;
}
