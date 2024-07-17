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
*參考手冊規範上所提供的暫存器位址資訊，暫存器資訊，編寫相關.h及.c檔，並利用define
### GPI0 struct
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
### RCC struct
```
typedef struct
{
	__vo uint32_t CR;   	 //0x00 , RCC clock control register
	__vo uint32_t PLLCFGR;   //0x04 , RCC PLL configuration register
	__vo uint32_t CFGR;      //0x08 , RCC clock configuration register
	__vo uint32_t CIR;       //0x0C , RCC clock interrupt register
	__vo uint32_t AHB1RSTR;  //0x10 , RCC AHB1 peripheral reset register
	__vo uint32_t AHB2RSTR;  //0x14 , RCC AHB2 peripheral reset register
	__vo uint32_t AHB3RSTR;  //0x18 , RCC AHB3 peripheral reset register
	uint32_t RESERVED0;      //0x1C
	__vo uint32_t APB1RSTR;  //0x20 , RCC APB1 peripheral reset register
	__vo uint32_t APB2RSTR;  //0x24 , RCC APB2 peripheral reset register
	uint32_t RESERVED1[2];   //0x28,0x2C
	__vo uint32_t AHB1ENR;   //0x30 ,
	__vo uint32_t AHB2ENR;   //0x34
	__vo uint32_t AHB3ENR;   //0x38
	uint32_t RESERVED2;      //0x3C
	__vo uint32_t APB1ENR;   //0x40
	__vo uint32_t APB2ENR;   //0x44
	uint32_t RESERVED3[2];   //0x48,0x4C
	__vo uint32_t AHB1LPENR; //0x50
	__vo uint32_t AHB2LPENR; //0x54
	__vo uint32_t AHB3LPENR; //0x58
	uint32_t RESERVED4;      //0x5C
	__vo uint32_t APB1LPENR; //0x60
	__vo uint32_t APB2LPENR; //0x64
	uint32_t RESERVED5[2];   //0x68,0x6C
	__vo uint32_t BDCR;      //0x70
	__vo uint32_t CSR;       //0x74
	uint32_t RESERVED6[2];   //0x78,0x7C
	__vo uint32_t SSCGR;     //0x80
	__vo uint32_t PLLI2SCFGR;//0x84

}RCC_RegDef_t;
```
### SPI struct
```
typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;
}SPI_RegDef_t;
```




