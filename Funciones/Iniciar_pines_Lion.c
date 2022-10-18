#include "iniciar_pines_Lion.h"
#include "stm32f0xx_hal.h"
#include "Lion1.h"
extern Lion1_2 str;

void Init_Lion(void)
{
	
	 /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
	Init_buttons();
	Init_sensors();
	Init_arranque();
	
}

//GPIO
void Init_buttons(void)
{
	//CONFIGURACION PINES BOTONES
	GPIO_InitTypeDef GPIO_InitStruct;
	
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	/*Configure GPIO pin : PB0 */ 
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
//	GPIO_InitStruct.Pin = GPIO_PIN_15;//GPIO_PIN_4|GPIO_PIN_15;
//  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//  GPIO_InitStruct.Pull = GPIO_PULLUP;
//  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = GPIO_PIN_7;//GPIO_PIN_1|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
}
void Init_sensors(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	//SENSOR DERECHO
	GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//SENSORE DE FRENTE
	GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	#ifdef LION_MINISUMO 
  //GPIO_InitStruct.Pull = GPIO_NOPULL;
	#else
	//GPIO_InitStruct.Pull = GPIO_PULLUP;
	#endif
	if(str.PULL_SELECT ==0)
	{
		GPIO_InitStruct.Pull = GPIO_PULLUP;
	}
	else if(str.PULL_SELECT==1)
	{
		GPIO_InitStruct.Pull = GPIO_NOPULL;
	}
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
//	SENSORES NORMALES
//	#ifdef LION_MINISUMO 
	GPIO_InitStruct.Pin =GPIO_PIN_6;//|GPIO_PIN_8;//|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//	#else
	
//	#endif
	
}
void Init_arranque(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

