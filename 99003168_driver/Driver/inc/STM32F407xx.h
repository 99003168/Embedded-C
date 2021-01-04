/*
 * STM32F407xx.h
 *
 *  Created on: Sep 29, 2020
 *      Author: Training
 */
#include <stdint.h>

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

				//To find base addresses of the memories
#define FLASH_BASEADDR			 0x08000000U
#define SRAM1_BASEADDR			 0x20000000U
#define SRAM2_BASEADDR			 0x2001C000U
#define SRAM 		  			 0x20000000U
#define ROM_BASEADDR   		   	 0x1FFF0000U

				// To find bus address
#define APB1_BASEADDR			 0x40000000U
#define APB2_BASEADDR			 0x40010000U
#define AHB1_BASEADDR			 0x40020000U
#define AHB2_BASEADDR			 0x50000000U

				//To find the base address of the peripheral hanging on AHB1
#define GPIOA_BASEADDR 				 	 (AHB1_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR					 (AHB1_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR					 (AHB1_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR					 (AHB1_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR  				 (AHB1_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR 					 (AHB1_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR 					 (AHB1_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR 					 (AHB1_BASEADDR + 0x1C00U)
#define GPIOI_BASEADDR 					 (AHB1_BASEADDR + 0x2000U)
#define RCC_BASEADDR					 (AHB1_BASEADDR + 0x3800U)

				//To find the base address of the peripheral hanging on APB1
#define I2C1 		(APB1_BASEADDR + 0x5400U)
#define I2C2 		(APB1_BASEADDR + 0x5800U)
#define I2C3 		(APB1_BASEADDR + 0x5C00U)
#define SPI2 		(APB1_BASEADDR + 0x3800U)
#define SPI3 		(APB1_BASEADDR + 0x3C00U)
#define USART2 		(APB1_BASEADDR + 0x4400U)
#define USART3 		(APB1_BASEADDR + 0x4800U)

				//To find the base address of the peripheral hanging on APB2
#define SPI1 		(APB2_BASEADDR + 0x3000U)
#define USART1 		(APB2_BASEADDR + 0x1000U)
#define USART6 		(APB2_BASEADDR + 0x1400U)
#define EXTI 		(APB2_BASEADDR + 0x3C00U)
#define SYSCFG 		(APB2_BASEADDR + 0x3800U)

				//Registers or Reg structures of GPIOA peripherals
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_REGDEF_t;

				//Registers or Reg structure of RCC
typedef struct
{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_PLLCFGR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    volatile uint32_t no1;
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t no2;
    volatile uint32_t no8;
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t no3;
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_APB2ENRH;
    volatile uint32_t no4;
    volatile uint32_t no9;
    volatile uint32_t RCC_AHB1LPENRRH;
    volatile uint32_t RCC_AHB2LPENRFRH;
    volatile uint32_t RCC_AHB3LPENRRH;
    volatile uint32_t no5;
    volatile uint32_t RCC_APB1LPENR;
    volatile uint32_t RCC_APB2LPENR;
    volatile uint32_t no6;
    volatile uint32_t no10;
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
    volatile uint32_t no7;
    volatile uint32_t no11;
    volatile uint32_t RCC_SSCGR;
    volatile uint32_t RCC_PLLI2SCFGR;
    volatile uint32_t RCC_PLLSAICFGR;
    volatile uint32_t RCC_DCKCFGR;
}RCC_REGDEF_t;


					//Peripheral definition for GPIO
#define GPIOA 		((GPIO_REGDEF_t*) GPIOA_BASEADDR)
#define GPIOB 		((GPIO_REGDEF_t*) GPIOB_BASEADDR)
#define GPIOC 		((GPIO_REGDEF_t*) GPIOC_BASEADDR)
#define GPIOD 		((GPIO_REGDEF_t*) GPIOD_BASEADDR)
#define GPIOE 		((GPIO_REGDEF_t*) GPIOE_BASEADDR)
#define GPIOF 		((GPIO_REGDEF_t*) GPIOF_BASEADDR)
#define GPIOG 		((GPIO_REGDEF_t*) GPIOG_BASEADDR)
#define GPIOH 		((GPIO_REGDEF_t*) GPIOH_BASEADDR)
#define GPIOI 		((GPIO_REGDEF_t*) GPIOI_BASEADDR)

					// Peripheral definition for RCC
#define RCC 		((RCC_REGDEF_t*) RCC_BASEADDR)


					//Clock enable macros for GPIOx
#define GPIOA_PCLK_EN() 			(RCC->AHB1ENR |=(1<<0))
#define GPIOB_PCLK_EN() 			(RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLK_EN() 			(RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLK_EN() 			(RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLK_EN() 			(RCC->AHB1ENR |=(1<<4))
#define GPIOF_PCLK_EN() 			(RCC->AHB1ENR |=(1<<5))
#define GPIOG_PCLK_EN() 			(RCC->AHB1ENR |=(1<<6))
#define GPIOH_PCLK_EN() 			(RCC->AHB1ENR |=(1<<7))
#define GPIOI_PCLK_EN() 			(RCC->AHB1ENR |=(1<<8))

					//Clock Disable macros for GPIOx
#define GPIOA_PCLK_DI() 			(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI() 			(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI() 			(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI() 			(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI() 			(RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI() 			(RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI() 			(RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI() 			(RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DI() 			(RCC->AHB1ENR &= ~(1<<8))

					// some important macros
#define ENABLE 						1
#define DISABLE 					0
#define SET 						ENABLE
#define RESET 						DISABLE
#define GPIO_PIN_SET				SET
#define GPIO_PIN_RESET				RESET

#define GPIOA_REG_RESET()			do{(RCC->AHB1RSTR |=1<<0); (RCC->AHB1RSTR &=~(1<<0));}while(0)
#define GPIOB_REG_RESET()			do{(RCC->AHB1RSTR |=1<<1); (RCC->AHB1RSTR &=~(1<<1));}while(0)
#define GPIOC_REG_RESET()			do{(RCC->AHB1RSTR |=1<<2); (RCC->AHB1RSTR &=~(1<<2));}while(0)
#define GPIOD_REG_RESET()			do{(RCC->AHB1RSTR |=1<<3); (RCC->AHB1RSTR &=~(1<<3));}while(0)
#define GPIOE_REG_RESET()			do{(RCC->AHB1RSTR |=1<<4); (RCC->AHB1RSTR &=~(1<<4));}while(0)
#define GPIOF_REG_RESET()			do{(RCC->AHB1RSTR |=1<<5); (RCC->AHB1RSTR &=~(1<<5));}while(0)
#define GPIOG_REG_RESET()			do{(RCC->AHB1RSTR |=1<<6); (RCC->AHB1RSTR &=~(1<<6));}while(0)
#define GPIOH_REG_RESET()			do{(RCC->AHB1RSTR |=1<<7); (RCC->AHB1RSTR &=~(1<<7));}while(0)
#define GPIOI_REG_RESET()			do{(RCC->AHB1RSTR |=1<<8); (RCC->AHB1RSTR &=~(1<<8));}while(0)

#include "stm32f407xx_gpio_driver.h"
#endif /* INC_STM32F407XX_H_ */
