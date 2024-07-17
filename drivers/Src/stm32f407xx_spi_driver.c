/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: May 12, 2024
 *      Author: user
 */

#include "stm32f407xx_spi_driver.h"


//Peripheral clock setup
/*******************
*   	@fn		- SPI_PeriClockControl
*
*	@brief		- This function enables or disables peripheral clock for the given SPI port
*
*	@param[in]	- base address of the spi peripheral
*	@param[in]	- ENABLE or DISABLE macros
*	@param[in]
*
*	@return		- none
*
*	@Note		- none
*/
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx , uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if(pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if(pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}

	}
	else
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_DI();
		}
		else if(pSPIx == SPI2)
		{
			SPI2_PCLK_DI();
		}
		else if(pSPIx == SPI3)
		{
			SPI3_PCLK_DI();
		}
	}
}


//Init and DeInit
/*******************
*   	@fn		- SPI_Init
*
*	@brief		-
*
*	@param[in]	-
*	@param[in]	-
*	@param[in]
*
*	@return		- none
*
*	@Note		- none
*/
void SPI_Init  (SPI_Handle_t *pSPIHandle)
{
	//peripheral clock enable
	SPI_PeriClockControl(pSPIHandle->pSPIx,ENABLE);


	//first configure the SPI_CR1 register
	uint32_t tempreg = 0 ;

	//1. configure the device mode
	tempreg |= pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;

	//2. configure the bus config
	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		//BIDI mode should be cleared
		tempreg &= ~(1<<SPI_CR1_BIDIMODE);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		//BIDI mode should be set
		tempreg |=(1<<SPI_CR1_BIDIMODE);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_S_RXONLY)
	{
		//BIDI mode should be cleared
		tempreg &= ~(1<<SPI_CR1_BIDIMODE);
		//RXonly bit must be set
		tempreg |=  (1<<SPI_CR1_RXONLY);
	}

	//3. Configure the spi serial clock speed (baud rate)
	tempreg |= pSPIHandle->SPIConfig.SPI_SclkSpeed <<SPI_CR1_BR;

	//4. Configure the DFF
	tempreg |= pSPIHandle->SPIConfig.SPI_DFF <<SPI_CR1_DFF ;

	//5. Configure the CPOL
	tempreg |= pSPIHandle->SPIConfig.SPI_CPOL <<SPI_CR1_CPOL ;

	//6. Configure the CPHA
	tempreg |= pSPIHandle->SPIConfig.SPI_CPHA <<SPI_CR1_CPHA ;

	pSPIHandle->pSPIx->CR1 = tempreg;
}

/*******************
*   	@fn		- SPI_DeInit
*
*	@brief		-
*
*	@param[in]	-
*	@param[in]	-
*	@param[in]
*
*	@return		- none
*
*	@Note		- none
*/
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{
	if (pSPIx == SPI1) {
		SPI1_REG_RESET();
	} else if (pSPIx == SPI2) {
		SPI2_REG_RESET();
	} else if (pSPIx == SPI3) {
		SPI3_REG_RESET();
	}
}

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx,uint32_t FlagName)
{
	if(pSPIx->SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}

/*******************
*   	@fn		- SPI_SendData
*
*	@brief		-
*
*	@param[in]	-
*	@param[in]	-
*	@param[in]
*
*	@return		- none
*
*	@Note		- This is blocking call
*/
void SPI_SendData   (SPI_RegDef_t *pSPIx , uint8_t *pTxBuffer , uint32_t Len)
{
	while(Len>0)
	{
		//1.wait until TXE is set
		while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG)==FLAG_RESET);

		//2.check the DFF in CR1
		if(pSPIx->CR1 & (1<< SPI_CR1_DFF))
		{
			//16 bit DFF
			//1. load the data in to the DR
			pSPIx->DR = *((uint16_t*)pTxBuffer);
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;
		}
		else
		{
			//8 bit DFF
			pSPIx->DR = *pTxBuffer;
			Len--;
			pTxBuffer++;
		}
	}
}

void SPI_ReceiveData(SPI_RegDef_t *pSPIx , uint8_t *pRxBuffer , uint32_t Len)
{
	while(Len>0)
	{
		//1.wait until RXNE is set
		while(SPI_GetFlagStatus(pSPIx,SPI_RXNE_FLAG)==FLAG_RESET);

		//2.check the DFF in CR1
		if(pSPIx->CR1 & (1<< SPI_CR1_DFF))
		{
			//16 bit DFF
			//1. load the data from DR to Rxbuffer address
			*((uint16_t*)pRxBuffer)=pSPIx->DR;
			Len--;
			Len--;
			(uint16_t*)pRxBuffer++;
		}
		else
		{
			//8 bit DFF
			*(pRxBuffer)=pSPIx->DR;
			Len--;
			pRxBuffer++;
		}
	}
}


void SPI_PeripheralControl(SPI_RegDef_t *pSPIx,uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		pSPIx->CR1 |= (1<<SPI_CR1_SPE);
	}
	else
	{
		pSPIx->CR1 &= ~(1<<SPI_CR1_SPE);
	}
}


void SPI_SSIConfig(SPI_RegDef_t *pSPIx,uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
		{
			pSPIx->CR1 |= (1<<SPI_CR1_SSI);
		}
		else
		{
			pSPIx->CR1 &= ~(1<<SPI_CR1_SSI);
		}
}



void SPI_SSOEConfig(SPI_RegDef_t *pSPIx,uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
		{
			pSPIx->CR2 |= (1<<SPI_CR2_SSOE);
		}
		else
		{
			pSPIx->CR2 &= ~(1<<SPI_CR2_SSOE);
		}
}
