/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: 30-Sep-2020
 *      Author: Training
 */
#include "stm32f407xx_gpio_driver.h"
#include <stdint.h>

/*
 *
 * @Brief description: function to eanble RCC clock
 *
 * @Function-GPIOX_PCLK_EN(),where x=a..i
 * @Param1-GPIO_REGDEF_t *pGPIOx
 * @Param2-uint8_t EnorD
 * @Definition-GPIO Clock enable and disable-
 * @Design by-Rahul L
 * @ date & time-01/10/2020
 *
 *
 */

void GPIO_PERICLKCTRL(GPIO_REGDEF_t *pGPIOx, uint8_t EorDi)
{
	if(EorDi==ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{
				if(pGPIOx == GPIOA)
				{
					GPIOA_PCLK_DI();
				}
				else if(pGPIOx == GPIOB)
				{
					GPIOB_PCLK_DI();
				}
				else if(pGPIOx == GPIOC)
				{
					GPIOC_PCLK_DI();
				}
				else if(pGPIOx == GPIOD)
				{
					GPIOD_PCLK_DI();
				}
				else if(pGPIOx == GPIOE)
				{
					GPIOE_PCLK_DI();
				}
				else if(pGPIOx == GPIOF)
				{
					GPIOF_PCLK_DI();
				}
				else if(pGPIOx == GPIOG)
				{
					GPIOG_PCLK_DI();
				}
				else if(pGPIOx == GPIOH)
				{
					GPIOH_PCLK_DI();
				}
				else if(pGPIOx == GPIOI)
				{
					GPIOI_PCLK_DI();
				}
	}
}

/*
 *
 * @Brief description:GPIO Clock enable and disable
 * @Function-gPIO Port intzatization
 * @Param1-GPIO_Handle_t *
 * @Definition-
 * @Design by-Rahul L
 * @ date & time-01/10/2020
 * -
 *
 */

void GPIO_INIT(GPIO_HANDLE_t *GPIOHANDLE)
{
	//Init Mode
	uint32_t temp=0;
	temp = (GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINMODE<<(2 *(GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINNUMBER)));
	(GPIOHANDLE->pGPIOx->MODER) &= ~(0x03<<2*GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINNUMBER); //First Reset the same pins and then set the values
	GPIOHANDLE->pGPIOx->MODER |=temp;
	//Config Speed
	temp=0;
	temp = (GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINSPEED <<(2 * (GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINNUMBER)));
	(GPIOHANDLE->pGPIOx->OSPEEDR) &= ~(0x03<<2*GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINNUMBER);
	GPIOHANDLE->pGPIOx->OSPEEDR |=temp;

	//Config Pull up and pull down
	temp=0;
	temp = (GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINPUPDCONTROL << (2*(GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINNUMBER)));
	(GPIOHANDLE->pGPIOx->PUPDR) &= ~(0x03<<2*GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINNUMBER);
	GPIOHANDLE->pGPIOx->PUPDR |=temp;

	//Config Output type
	temp=0;
	temp = (GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINOPTYPE << (GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINNUMBER));
	(GPIOHANDLE->pGPIOx->OTYPER) &= ~(0x01<<GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINNUMBER);
	GPIOHANDLE->pGPIOx->OTYPER |=temp;

	//Config Alternating Function

	if(GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINMODE == GPIO_MODE_AFN)
	{
		uint8_t temp1=0, temp2=0;
		temp1 = GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINNUMBER/8;
		temp2 = GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINNUMBER%8;
		GPIOHANDLE->pGPIOx->AFR[temp1] &= ~(0x0F<<4*temp2);
		GPIOHANDLE->pGPIOx->AFR[temp1]= GPIOHANDLE->GPIO_PINCONFIG.GPIO_PINALTFUNMODE<<(4*temp2);
	}

}
/*
 *
 *
 * @Brief description:reset of GPIO port
 * @Function-GPIO_DInit
 * @Param1-GPIO_REGDEF_t*
 * @Definition-
 * @Design by- Rahul L
 * @ date & time- 01/10/2020
 *
 */

void GPIO_DINIT(GPIO_REGDEF_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}
	else if(pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	}
	else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}
	else if(pGPIOx == GPIOI)
	{
		GPIOI_REG_RESET();
	}
}
/*
 *
 *
 * @Brief description:GPIO Input from pin
 * @Function-GPIO_ReadFromInptPin
 * @Param1-GPIO_REGDEF_t *
 * @Definition-
 * @Design by- Rahul L
 * @ date & time- 01/10/2020
 *
 *
 */

uint8_t GPIO_READFROMIPPIN(GPIO_REGDEF_t *pGPIOx, uint8_t PINNO)
{
	uint8_t value=0;
	value = (uint8_t)(pGPIOx->IDR>>PINNO)&(0x00000001);
	return value;
}

/*
 *
 *
 * * @Brief description:Input from port input
 * @Function-GPIO_ReadFromInptPort
 * @Param1-GPIO_REGDEF_t *
 * @Definition-
 * @Design by- Rahul L
 * @ date & time- 01/10/2020
 *
 *
 */

uint16_t GPIO_READFROMIPPORT(GPIO_REGDEF_t *pGPIOx)
{
	uint16_t value=0;
	value = (uint16_t)(pGPIOx->IDR);
	return value;

}

/*
 *
 *
 * @Brief description:output port pin set or reset
 * @Function-GPIO_WriteToOutputPin
 * @Param1-GPIO_REGDEF_t *
 * @Definition-
 * @Design by- Rahul L
 * @ date & time- 01/10/2020
 *
 *
 */

void GPIO_WRITETOOUPUTPIN(GPIO_REGDEF_t *pGPIOx, uint8_t PINNO, uint8_t VALUE)
{
	if(VALUE == GPIO_PIN_SET)
	{
		pGPIOx->ODR|=(1<<PINNO);
	}
	else
	{
		pGPIOx->ODR&=~(1<<PINNO);
	}
}

/*
 *
 * @Brief description:to write to output port
 * @Function-GPIO_WriteToOutputPort
 * @Param1-GPIO_REGDEF_t *
 * @Definition-
 * @Design by- Rahul L
 * @ date & time- 01/10/2020
 *
 */

void GPIO_WRITETOOUPUTPORT(GPIO_REGDEF_t *pGPIOx, uint16_t VALUE)
{
	pGPIOx->ODR = VALUE;
}

/*
 *
 * @Function-to call toggle function
 * @Param1-GPIO_REGDEF_t *
 * @Definition-
 * @Design by-Rahul L
 * @ date & time- 01/10/2020
 *
 */

void GPIO_TOGGLEOUTPUTPIN(GPIO_REGDEF_t *pGPIOx, uint8_t PINNO)
{
	pGPIOx->ODR^=(1<<PINNO);
}
