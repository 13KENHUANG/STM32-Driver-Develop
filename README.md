# [Project] STM32 driver develop
## Introduction
*使用嵌入式C語言並參使用者手冊的資訊編寫一套STM32 driver檔，預期能支援GPIO、SPI、I2C、USART等通訊協定*
## Environment
- Windows 10
- CubeMXIDE

## Features
- [x] GPIO
- [x] SPI
- [ ] I2C
- [ ] USART
## Implementation
###GPI0 struct
```
typedef struct
{
	__vo uint32_t MODER;   //0x00 , GPIO port mode               register
	__vo uint32_t OTYPER;  //0x04 , GPIO port output type        register
	__vo uint32_t OSPEEDR; //0x08 , GPIO port output speed       register
	__vo uint32_t PUPDR;   //0x0C , GPIO port pull-up/pull-down  register
	__vo uint32_t IDR;     //0x10 , GPIO port input data         register
	__vo uint32_t ODR;     //0x14 , GPIO port output data        register
	__vo uint32_t BSRR;    //0x18 , GPIO port bit set/reset      register
	__vo uint32_t LCKR;    //0x1C , GPIO port configuration lock register
	__vo uint32_t AFR[2];  //0x20 , GPIO alternate function low  register
	                       //0x24 , GPIO alternate function high register
}GPIO_RegDef_t;
```




