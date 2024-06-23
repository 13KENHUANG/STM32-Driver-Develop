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

	}
}
