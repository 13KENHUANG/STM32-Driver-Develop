
#include "stm32f407xx.h"

#define LOW 0
#define BTN_PRESSED LOW

void delay(void)
{
	for(uint32_t i=0 ; i<500000/2;i++)
	{

	}
}

int main(void)
{
	GPIO_Handle_t GpioLed , GPIOBtn;

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOD,ENABLE);
	GPIO_Init(&GpioLed);


	GPIOBtn.pGPIOx = GPIOB;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GPIO_PeriClockControl(GPIOB,ENABLE);
	GPIO_Init(&GPIOBtn);


	while(1)
	{

		if(GPIO_ReadFromInputPin(GPIOB,GPIO_PIN_NO_12)==BTN_PRESSED)
		{
			delay();
			GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_15);
		}

	}
	return 0;
}
