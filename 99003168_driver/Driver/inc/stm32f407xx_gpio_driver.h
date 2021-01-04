/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: 30-Sep-2020
 *      Author: Training
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_
#include "STM32F407xx.h"
#include <stdint.h>


typedef struct
{
	uint8_t GPIO_PINNUMBER;
	uint8_t GPIO_PINNAME;
	uint8_t GPIO_PINMODE;
	uint8_t GPIO_PINSPEED;
	uint8_t GPIO_PINOPTYPE;
	uint8_t GPIO_PINPUPDCONTROL;
	uint8_t GPIO_PINALTFUNMODE;
}GPIO_PINCONFIG_t;


typedef struct
{
	GPIO_REGDEF_t *pGPIOx;
	GPIO_PINCONFIG_t GPIO_PINCONFIG;
}GPIO_HANDLE_t;

//GPIO_PinNumber of GPIOx
#define GPIO_PINNUMBER_0  		0
#define GPIO_PINNUMBER_1  		1
#define GPIO_PINNUMBER_2  		2
#define GPIO_PINNUMBER_3  		3
#define GPIO_PINNUMBER_4  		4
#define GPIO_PINNUMBER_5  		5
#define GPIO_PINNUMBER_6  		6
#define GPIO_PINNUMBER_7  		7
#define GPIO_PINNUMBER_8  		8
#define GPIO_PINNUMBER_9  		9
#define GPIO_PINNUMBER_10  		10
#define GPIO_PINNUMBER_11  		11
#define GPIO_PINNUMBER_12 		12
#define GPIO_PINNUMBER_13  		13
#define GPIO_PINNUMBER_14  		14
#define GPIO_PINNUMBER_15  		15

//Possible Modes
#define GPIO_MODE_IN 							0
#define GPIO_MODE_OUT  							1
#define GPIO_MODE_AFN			 				2
#define GPIO_MODE_ANALOG						3

//GPIO_PinSpeed
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_HIGH			2
#define GPIO_SPEED_VERY_HIGH  	3

//GPIO_PinOPType
#define GPIO_OP_TYPE_PP 		0
#define GPIO_OP_TYPE_OD			1

//GPIO_PinPuPdControl
#define GPIO_NO_PU_PD 				0
#define GPIO_PU 					1
#define GPIO_PD				 		2
#define GPIO_RESERVED		 		3

//GPIO_PinAltFunMode
/*#define GPIO_AFMODE_AF0					0
#define GPIO_AFMODE_AF1					1
#define GPIO_AFMODE_AF2					2
#define GPIO_AFMODE_AF3					3
#define GPIO_AFMODE_AF4					4
#define GPIO_AFMODE_AF5					5
#define GPIO_AFMODE_AF6					6
#define GPIO_AFMODE_AF7					7
#define GPIO_AFMODE_AF8					8
#define GPIO_AFMODE_AF9					9
#define GPIO_AFMODE_AF10					10
#define GPIO_AFMODE_AF11					11
#define GPIO_AFMODE_AF12					12
#define GPIO_AFMODE_AF13					13
#define GPIO_AFMODE_AF14					14
#define GPIO_AFMODE_AF15					15
*/

void GPIO_INIT(GPIO_HANDLE_t *GPIOHANDLE);

void GPIO_DINIT(GPIO_REGDEF_t *pGPIOx);

void GPIO_PERICLKCTRL(GPIO_REGDEF_t *pGPIOx, uint8_t EorDi);

uint8_t GPIO_READFROMIPPIN(GPIO_REGDEF_t *pGPIOx, uint8_t PINNO);
uint16_t GPIO_READFROMIPPORT(GPIO_REGDEF_t *pGPIOx);

void GPIO_WRITETOOUPUTPIN(GPIO_REGDEF_t *pGPIOx, uint8_t PINNO, uint8_t VALUE);
void GPIO_WRITETOOUPUTPORT(GPIO_REGDEF_t *pGPIOx, uint16_t VALUE);

void GPIO_TOGGLEOUTPUTPIN(GPIO_REGDEF_t *pGPIOx, uint8_t PINNO);
#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
