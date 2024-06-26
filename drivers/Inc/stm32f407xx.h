/*
 * stm32f407xx.h
 *
 *  Created on: Apr 16, 2024
 *      Author: user
 */
#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

#define __vo volatile


/******************START:Processor Specific Details*****************/
/*
 * ARM cortex Mx Processor NVIC ISERx register Addresses
 */
#define NVIC_ISER0       ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1       ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2       ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3       ((__vo uint32_t*)0xE000E10c)

/*
 * ARM cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER0       ((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1       ((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2       ((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3       ((__vo uint32_t*)0xE000E18c)

/*
 * ARM cortex Mx Processor　Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR      ((__vo uint32_t*)0xE000E400)

/*
 * ARM cortex Mx Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BIATS_IMPLEMENTED			4

/*
 *  base addresses of Flash and SRAM memories
 */
#define FLASH_BASEADDR               0x08000000U    /*user_manual p.71*/
#define SRAM1_BASEADDR			     0x20000000U
#define SRAM2_BASEADDR			     0x2001C000U
#define ROM			   				 0x1FFF0000U
#define SRAM                         SRAM1_BASEADDR



/*
 *  AHBx and APBx Bus Peripheral base addr
 */
#define PERIPH_BASE 				  0x40000000U
#define APB1PERIPH_BASEADDR 		  PERIPH_BASE
#define APB2PERIPH_BASEADDR 	      0x40010000U
#define AHB1PERIPH_BASEADDR 		  0x40020000U
#define AHB2PERIPH_BASEADDR        	  0x50000000U


/*
 * Base address of peripherals which are hanging on AHB1 bus
 */
#define GPIOA_BASEADDR               (AHB1PERIPH_BASEADDR+0x0000)
#define GPIOB_BASEADDR               (AHB1PERIPH_BASEADDR+0x0400)
#define GPIOC_BASEADDR               (AHB1PERIPH_BASEADDR+0x0800)
#define GPIOD_BASEADDR               (AHB1PERIPH_BASEADDR+0x0C00)
#define GPIOE_BASEADDR               (AHB1PERIPH_BASEADDR+0x1000)
#define GPIOF_BASEADDR               (AHB1PERIPH_BASEADDR+0x1400)
#define GPIOG_BASEADDR               (AHB1PERIPH_BASEADDR+0x1800)
#define GPIOH_BASEADDR               (AHB1PERIPH_BASEADDR+0x1C00)
#define GPIOI_BASEADDR               (AHB1PERIPH_BASEADDR+0x2000)
#define RCC_BASEADDR			     (AHB1PERIPH_BASEADDR+0x3800)

/*
 * Base address of peripherals which are hanging on APB1 bus
 */
#define I2C1_BASEADDR                (APB1PERIPH_BASEADDR+0x5400)
#define I2C2_BASEADDR			     (APB1PERIPH_BASEADDR+0x5800)
#define I2C3_BASEADDR				 (APB1PERIPH_BASEADDR+0x5C00)

#define SPI2_BASEADDR  	             (APB1PERIPH_BASEADDR+0x3800)
#define SPI3_BASEADDR                (APB1PERIPH_BASEADDR+0x3C00)

#define USART2_BASEADDR              (APB1PERIPH_BASEADDR+0x4400)
#define USART3_BASEADDR              (APB1PERIPH_BASEADDR+0x4800)
#define UART4_BASEADDR               (APB1PERIPH_BASEADDR+0x4C00)
#define UART5_BASEADDR               (APB1PERIPH_BASEADDR+0x5000)

/*
 * Base address of peripherals which are hanging on APB2 bus
 */
#define EXTI_BASEADDR			     (APB2PERIPH_BASEADDR+0x3C00)
#define SPI1_BASEADDR			     (APB2PERIPH_BASEADDR+0x3000)
#define SYSCFG_BASEADDR			     (APB2PERIPH_BASEADDR+0x3800)
#define USART1_BASEADDR			     (APB2PERIPH_BASEADDR+0x1000)
#define USART6_BASEADDR			     (APB2PERIPH_BASEADDR+0x1400)


//******************peripheral register definition structures*************
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

/*
 * peripheral register definition structure for EXTI
 */
typedef struct
{
	__vo uint32_t IMR;  	 //0x00 , Interrupt mask register
	__vo uint32_t RTSR; 	 //0x08 , Event mask register
	__vo uint32_t FTSR;  	 //0x0C , Rising trigger selection register
	__vo uint32_t SWIER;     //0x10 , Falling trigger selection register
	__vo uint32_t PR;    	 //0x14 , Pending register

}EXIT_RegDef_t;

/*
 * peripheral register definition structure for SYSCFG
 */
typedef struct
{
	__vo uint32_t MEMRMP;  	 	//0x00
	__vo uint32_t PMC;	     	//0x04
	__vo uint32_t EXTICR[4]; 	//0x08~0x14
	__vo uint32_t RESERVED1[2]; //0x18~0x1C
	__vo uint32_t CMPCR;     	//0x20

}SYSCFG_RegDef_t;

/*
 * peripheral register definition structure for SPI
 */
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

/*
 * peripheral definitions
 */
#define GPIOA       ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB       ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC       ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD       ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE       ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF       ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG       ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH       ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI       ((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC         ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI 		((EXIT_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG      ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1        ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2        ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3        ((SPI_RegDef_t*)SPI3_BASEADDR)

//=================Enable=====================
/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN() 	 (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN() 	 (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN() 	 (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN() 	 (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN() 	 (RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN() 	 (RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN() 	 (RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN() 	 (RCC->AHB1ENR |= (1<<7))
#define GPIOI_PCLK_EN() 	 (RCC->AHB1ENR |= (1<<8))

/*
 * Clock Enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN()       (RCC->APB1ENR |=(1<<21))
#define I2C2_PCLK_EN()       (RCC->APB1ENR |=(1<<22))
#define I2C3_PCLK_EN()       (RCC->APB1ENR |=(1<<23))


/*
 * Clock Enable Macros for SPIx peripherals
 */
#define SPI1_PCLK_EN()       (RCC->APB2ENR |=(1<<12))
#define SPI2_PCLK_EN()       (RCC->APB1ENR |=(1<<14))
#define SPI3_PCLK_EN()       (RCC->APB1ENR |=(1<<15))
#define SPI4_PCLK_EN()       (RCC->APB2ENR |=(1<<13))


/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART1_PCLK_EN()     (RCC->APB2ENR |=(1<<4))
#define USART2_PCLK_EN()     (RCC->APB1ENR |=(1<<17))
#define USART3_PCLK_EN()     (RCC->APB1ENR |=(1<<18))
#define USART4_PCLK_EN()     (RCC->APB1ENR |=(1<<19))
#define USART5_PCLK_EN()     (RCC->APB1ENR |=(1<<20))
#define USART6_PCLK_EN()     (RCC->APB2ENR |=(1<<5))

/*
 * Clock Enable Macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_EN()     (RCC->APB2ENR |=(1<<14))


//=================Disable====================
/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI() 	 (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI() 	 (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI() 	 (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI() 	 (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI() 	 (RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI() 	 (RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI() 	 (RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI() 	 (RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DI() 	 (RCC->AHB1ENR &= ~(1<<8))

/*
 * Clock Disable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_DI()       (RCC->APB1ENR &=~(1<<21))
#define I2C2_PCLK_DI()       (RCC->APB1ENR &=~(1<<22))
#define I2C3_PCLK_DI()       (RCC->APB1ENR &=~(1<<23))

/*
 * Clock Disable Macros for SPIx peripherals
 */
#define SPI1_PCLK_DI()       (RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI()       (RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI()       (RCC->APB1ENR &= ~(1<<15))
#define SPI4_PCLK_DI()       (RCC->APB2ENR &= ~(1<<13))

/*
 * Clock Disable Macros for USARTx peripherals
 */
#define USART1_PCLK_DI()     (RCC->APB2ENR &= ~(1<<4))
#define USART2_PCLK_DI()     (RCC->APB1ENR &= ~(1<<17))
#define USART3_PCLK_DI()     (RCC->APB1ENR &= ~(1<<18))
#define USART4_PCLK_DI()     (RCC->APB1ENR &= ~(1<<19))
#define USART5_PCLK_DI()     (RCC->APB1ENR &= ~(1<<20))
#define USART6_PCLK_DI()     (RCC->APB2ENR &= ~(1<<5))

/*
 * Clock Disable Macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_DI()     (RCC->APB2ENR &= ~(1<<14))

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<0)); (RCC->AHB1RSTR &= ~(1<<0));}while(0)
#define GPIOB_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<1)); (RCC->AHB1RSTR &= ~(1<<1));}while(0)
#define GPIOC_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<2)); (RCC->AHB1RSTR &= ~(1<<2));}while(0)
#define GPIOD_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<3)); (RCC->AHB1RSTR &= ~(1<<3));}while(0)
#define GPIOE_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<4)); (RCC->AHB1RSTR &= ~(1<<4));}while(0)
#define GPIOF_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<5)); (RCC->AHB1RSTR &= ~(1<<5));}while(0)
#define GPIOG_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<6)); (RCC->AHB1RSTR &= ~(1<<6));}while(0)
#define GPIOH_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<7)); (RCC->AHB1RSTR &= ~(1<<7));}while(0)
#define GPIOI_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<8)); (RCC->AHB1RSTR &= ~(1<<8));}while(0)

/*
 * returns port code for given GPIOx base address
 */
#define GPIO_BASEADDR_TO_CODE(x) ( (x == GPIOA) ? 0 : \
								   (x == GPIOB) ? 1 : \
								   (x == GPIOC) ? 2 : \
								   (x == GPIOD) ? 3 : \
								   (x == GPIOE) ? 4 : \
								   (x == GPIOF) ? 5 : \
								   (x == GPIOG) ? 6 : \
								   (x == GPIOH) ? 7 : 0)

/*
 * IRQ(Interrupt Reqest) Numbers of STM32F407 MCU
 * NOTE: update these macros with valid values according to your MCU
 */
#define IRQ_NO_EXIT0  		6
#define IRQ_NO_EXIT1  		7
#define IRQ_NO_EXIT2  		8
#define IRQ_NO_EXIT3  		9
#define IRQ_NO_EXIT4  		10
#define IRQ_NO_EXIT9_5  	23
#define IRQ_NO_EXIT15_10	40

/*
 * macros for all the possible prioity levels
 */
#define NVIC_IRQ_PRI0		0
#define NVIC_IRQ_PRI1		1
#define NVIC_IRQ_PRI2		2
#define NVIC_IRQ_PRI3		3
#define NVIC_IRQ_PRI4		4
#define NVIC_IRQ_PRI5		5
#define NVIC_IRQ_PRI6		6
#define NVIC_IRQ_PRI7		7
#define NVIC_IRQ_PRI8		8
#define NVIC_IRQ_PRI9		9
#define NVIC_IRQ_PRI10		10
#define NVIC_IRQ_PRI11		11
#define NVIC_IRQ_PRI12		12
#define NVIC_IRQ_PRI13		13
#define NVIC_IRQ_PRI14		14
#define NVIC_IRQ_PRI15		15

//some generic macros
#define ENABLE  		1
#define DISABLE 		0
#define SET     		ENABLE
#define RESET   		DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET

#include "stm32f407xx_gpio_drivers.h"
#include "stm32f407xx_spi_driver.h"

#endif /* INC_STM32F407XX_H_ */
