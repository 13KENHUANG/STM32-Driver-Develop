/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: May 12, 2024
 *      Author: user
 */

#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_

#include "stm32f407xx.h"

typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;   		//possible values from @GPIO_PIN_MODES
	uint8_t SPI_SclkSpeed;			//possible values from @GPIO_PIN_SPEED
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;

}SPI_Config_t;

typedef struct
{
	SPI_RegDef_t 	*pGPIOx;          //This holds the base address of the GPIO port to which the pin belongs
	SPI_Config_t SPIConfig;  		//This holds GPIO pin configuration settings
}SPI_Handle_t;

/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER   1
#define SPI_DEVICE_MODE_SLAVE    0

/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD			0
#define SPI_BUS_CONFIG_HD			1
#define SPI_BUS_CONFIG_S_RXONLY		2

/*
 * @SPI_SclkSpeed
 */
#define SPI_SCLK_SPEED_DIV2			0
#define SPI_SCLK_SPEED_DIV4			1
#define SPI_SCLK_SPEED_DIV8			2
#define SPI_SCLK_SPEED_DIV16		3
#define SPI_SCLK_SPEED_DIV32		4
#define SPI_SCLK_SPEED_DIV64		5
#define SPI_SCLK_SPEED_DIV128		6
#define SPI_SCLK_SPEED_DIV256		7

/*
 * @SPI_DFF
 */
#define SPI_DFF_8BITS				0
#define SPI_DFF_16BITS				1

/*
 * @CPOL
 */
#define SPI_CPOL_HIGH				1
#define SPI_CPOL_LOW				0

/*
 * @CPHA
 */
#define SPI_CPHA_HIGH				1
#define SPI_CPHA_LOW				0

/*
 * @SPI_SSM
 */
#define SPI_SSM_EN					1
#define SPI_SSM_DI					0

/*************************************************************************
 * 					APIs supported by this driver
 * 		For more information about the APIs check the function definitions
 * ***********************************************************************
 */
/*
 * Peripheral Clock setup
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx , uint8_t EnorDi);

//Init and Deinit
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Data Send and Receive
 */
void SPI_SendData(SPI_RegDef_t *pSPIx , uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer,uint32_t Len);

/*
 * IRQ Configuration and ISR handling
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber  , uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber,uint8_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);

/*
 * Other Peripheral Control APIs
 */



#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */